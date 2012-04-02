/* 
 * File:   StackModel.C
 * Author: Nathan Hansen
 * 
 * Created on March 27, 2012, 1:35 PM
 */
#include "StackModel.h"

//Namespace crazy time!
using namespace StackModelNameSpace;

StackModel::StackModel(int width, int height) :
Width(width < 10 ? 10 : width), Height(height < 10 ? 10 : height) {
    //Generate map. and items in each place.
    //populate the queue random events.
    //Generate the array.
    Map = new StackTile*[Width];
    for (int i = 0; i < Width; i++) {
        Map[i] = new StackTile[Height];
    }
    for (int j = 0; j < Width; j++) {
        for (int i = 0; i < Height; i++) {
            //Map[i][j];
        }
    }
}

StackModel::~StackModel() {
    for (int i = 0; i < Width; i++) {
        delete Map[i];
    }
}

StackTile * StackModel::getTileInfo(int XoffSet, int YoffSet) {
    
}

StackConsequence * StackModel::sufferConsequence() {
    
}
