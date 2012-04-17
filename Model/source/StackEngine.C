/* 
 * File:   StackEngine.C
 * Author: Nathan Hansen
 * 
 * Created on April 14, 2012, 11:34 AM
 */

#include "StackEngine.h"

using namespace StackModel;

StackEngine::StackEngine() {

}
/**
 * DON'T COPY ME
 * @param orig
 */
StackEngine::StackEngine(const StackEngine& orig) {
    throw 1;
}
StackEngine::~StackEngine() {
}
void StackEngine::LoadEngine(String& configFile, String& thingsLibrary, String& errorLog, String& messageLog, String& mapFile){
    
    
}
AbstractModelNameSpace::AbstractEvent* StackEngine::next(){
    return NULL;
}
AbstractModelNameSpace::AbstractTile * StackEngine::getTileInfo(int XoffSet, int YoffSet){
    return NULL;
}
void StackEngine::EndGame(){
    
}
bool StackEngine::AddEvent(AbstractModelNameSpace::AbstractEvent* event){
    return false;
}
