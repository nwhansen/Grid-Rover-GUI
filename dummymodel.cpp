#include "dummymodel.h"
#include <time.h>
DummyModel::DummyModel()
{
    //Generate Salt for seed.
    srand(time(NULL));
}

TileType DummyModel::getTile(int x, int y){
    //Dummy solution add 0 between x and y
    // 10 0 1
    // 1 0 01
    //std::string bob(x + "0"+ y);
    //int seed = atoi(bob.c_str());
    //srand(seed);
    int tileType = rand() % 4;
    return (TileType)tileType;
}
