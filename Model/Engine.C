/* 
 * File:   Engine.C
 * Author: Nathan Hansen
 * 
 * Created on April 17, 2012, 3:31 PM
 */

#include "Engine.h"
#include "cstdlib"
#include "GameOverEvent.h"
#include "GetCommandEvent.h"

String Engine::empty("");

Engine::~Engine() {
    //End the game
    EndGame();
    //Clean up now Since we can only deconstruct an object once we won't double delete pointers.
    for (int i = 0; i < Width; i++) {
        delete[] Map[i];
    }
    delete[] Map;
}

Engine::Engine(int width, int height, String& roverFile, String& thingsLibrary, String& errorLog, String& messageLog, String& configFile, String& mapFile)
: player1(1, 0, 0, 0, 0, roverFile), Width(width), Height(height), Factory(thingsLibrary), currentTime(0, 0, 0) {
    Logs.openLogs(messageLog, errorLog);
    Map = new Tile*[Width];
    for (int i = 0; i < Width; i++) {
        Map[i] = new Tile[Height];
    }
    for (int j = 0; j < Width; j++) {
        for (int i = 0; i < Height; i++) {
            //Select random map tile and convert it.
            Map[i][j].setProperties(Tile::to_tile_enum(rand() % 4));
        }
    }
    //Add one minute delay to the rover command and enqueue the end game after 3 titan days.
    EventQueue.push(new GameOverEvent(this, Titan::TitanTime(3, 0, 0) + currentTime));
    EventQueue.push(new GetCommandEvent(this, Titan::TitanTime(0, 0, 1) + currentTime));
    inProgress = true;
}

ResultType Engine::next() {
    if (EventQueue.empty()) return Fail;
    Event* tmp = EventQueue.top();
    EventQueue.pop();
    ResultType t = tmp->fire();
    delete tmp;
    return t;
}

Tile* Engine::getTileInfo(int XoffSet, int YoffSet) {
    //Check bounds
    if (XoffSet >= Width || YoffSet >= Height) return NULL;
    return &(Map[XoffSet][YoffSet]);
}

void Engine::EndGame() {
    if (EventQueue.empty()) return;
    Event *event;
    while (!EventQueue.empty()) {
        event = EventQueue.top();
        EventQueue.pop();
        delete event;
    }
    inProgress = false;
}

bool Engine::AddEvent(Event* event) {
    if (!inProgress || currentTime > event->fireTime()) {
        //Delete the event and return false;
        delete event;
        return false;
    }
    EventQueue.push(event);
    return true;
}

Rover* Engine::GetRover(int player) {
    if (player == 0)
        return &(this->player1);
}

