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

std::string Engine::empty("");

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
: player1(1, 0, roverFile), Width(width), Height(height), Factory(thingsLibrary), currentTime(0, 0, 0) {
    Logs.openLogs(messageLog, errorLog);
    Map = new Tile*[Width];
    for (int i = 0; i < Width; i++) {
        Map[i] = new Tile[Height];
    }
    bool isplaced = false;
    for (int j = 0; j < Width; j++) {
        for (int i = 0; i < Height; i++) {
            //Select random map tile and convert it.
            Map[j][i].setProperties(Tile::to_tile_enum(rand() % 4));
            //If we have about the center then do this.
            if( (Height/2) == i && (Width/2) == j && !isplaced){ //Not doesn't check if tile is invalid.
                Map[j][i].addItem(&player1);
                player1.SetXCoords(i, j);
                isplaced = true;
            }
        }
    }
    //Add one minute delay to the rover command and enqueue the end game after 3 titan days.
    EventQueue.push(new GameOverEvent(this, Titan::TitanTime(3, 0, 0).plus(currentTime)));
    EventQueue.push(new GetCommandEvent(this, Titan::TitanTime(0, 0, 1).plus(currentTime)));
    inProgress = true;
}

ResultType Engine::next() {
    if (EventQueue.empty()) return Fail;
    Event* tmp = EventQueue.top();
    EventQueue.pop();
    ResultType t = tmp->fire();
    currentTime = tmp->fireTime();
    delete tmp;
    return t;
}

Tile* Engine::getTileInfo(int XoffSet, int YoffSet) {
    //Check bounds
    if (XoffSet >= Width || YoffSet >= Height || !inProgress || YoffSet < 0 || XoffSet < 0) return NULL;
    return &(Map[XoffSet][YoffSet]);
}

void Engine::EndGame() {
    if (!EventQueue.empty()) {
        Event *event;
        while (!EventQueue.empty()) {
            event = EventQueue.top();
            EventQueue.pop();
            delete event;
        }
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
//    return NULL;
}

