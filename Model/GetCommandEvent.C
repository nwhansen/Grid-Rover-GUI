/*
 * File:   GetCommandEvent.C
 * Author: Lucas Adam M. Paul
 *
 * Created on 2012/04/17 16:44:24
 */

#include <stdio.h>
#include "Event.h"
#include "TitanTime.h"
#include "Engine.h"
#include "GetCommandEvent.h"
#include "MoveEvent.h"
#include "Rover.h"
#include "RoverInterface.h"
#include "Result.h"
#include "Communication.h"
#include "GameOverEvent.h"
#include "Logger.h"
#include "LookEvent.h"
using namespace Model;

GetCommandEvent::GetCommandEvent(Engine* m, Titan::TitanTime time) : Event(m, time) {
}

ResultType GetCommandEvent::fire() {
    Logging::Logger* log;
    Logging::Logger::aquireLogger(log);
    bool valid = false;
    Rover* rover = engine->GetRover(0);
    RoverInterface* ri = rover->GetRoverInterface();
    //Fail.
    ri->SendRoverCommand("get\n");
    Communication comm = ri->RecieveFormattedMessage();
    if (comm.command.compare("move") == 0) {
        if (comm.arguments.size() > 0 && comm.arguments.front().length() > 0) {
            char direction = tolower(comm.arguments.front()[0]);
            if (direction == 'e' || direction == 'n' || direction == 's' || direction == 'w') {
                Titan::TitanTime traveltime(0, 0, 20);
                engine->AddEvent(new MoveEvent(engine, completionTime.plus(traveltime), rover, direction));
                valid = true;
            }
        }
    } else if (comm.command.compare("look") == 0) {
        Logging::Logger::writeToLog(log, "Rover attempted invalid move");
    } else if (comm.command.compare("selfdestruct") == 0) {
        Logging::Logger::writeToLog(log, "Game ended by rover", false);
        Titan::TitanTime penaltytime(0, 0, 1);
        engine->AddEvent(new GameOverEvent(engine, completionTime.plus(penaltytime)));
    }
    if (!valid) {
        Logging::Logger::writeToLog(log, "Failed to get valid message", true);
        Titan::TitanTime penaltytime(0, 0, 1);
        engine->AddEvent(new GetCommandEvent(engine, completionTime.plus(penaltytime)));
        return Fail;
    }
    return Get;
}

