/* 
 * File:   Engine.C
 * Author: Nathan Hansen
 * 
 * Created on April 17, 2012, 3:31 PM
 */

#include "Engine.h"
#include "cstdlib"


String Engine::empty("");

Engine::~Engine() {
    for (int i = 0; i < Width; i++) {
        delete[] Map[i];
    }
    delete[] Map;
}

Engine::Engine(int width, int height, String& roverFile, String& thingsLibrary, String& errorLog, String& messageLog, String& configFile, String& mapFile) 
                : player1(1, 0, 0, 0, 0, roverFile), Width(width), Height(height), Factory(thingsLibrary) {
    Logs.openLogs(messageLog, errorLog);

    Map = new Tile*[Width];
    for (int i = 0; i < Width; i++) {
        Map[i] = new Tile[Height];
    }
    for (int j = 0; j < Width; j++) {
        for (int i = 0; i < Height; i++) {
            //Select random map tile and convert it.
            Map[i][j].setProperties(rand() % 4);
        }
    }
    
}

ResultType Engine::next() {
    Event* tmp = EventQueue.top();
    //Ok lets do the work
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

}

bool Engine::AddEvent(Event event) {
    //
}

Rover* Engine::GetRover(int player) {
    if (player == 0)
        return &(this->player1);
}

