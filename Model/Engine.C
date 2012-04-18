/* 
 * File:   Engine.C
 * Author: Nathan Hansen
 * 
 * Created on April 17, 2012, 3:31 PM
 */

#include "Engine.h"
void Engine::LoadEngine(int width, int height, String& roverfile, String& thingsLibrary, String& errorLog, String& messageLog, String& configFile, String& mapFile) : player1(roverfile){
    this->Width = width;
    this->Height = height;
    Factory.GenerateThings(thingsLibrary);
    
}
Result* Engine::next(){
}
Tile * Engine::getTileInfo(int XoffSet, int YoffSet){
}
void Engine::EndGame(){
}
bool Engine::AddEvent(Event event){
    //
}
Rover* Engine::GetRover(int player){
    return &(this->player1);
}

