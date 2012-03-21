#include "dummymodel.h"

DummyModel::DummyModel()
{
    //Generate Salt for seed.

}

std::string DummyModel::getTile(int x, int y){
    //Dummy solution add 0 between x and y
    // 10 0 1
    // 1 0 01
    std::string bob(x + "0"+ y);
    int seed = atoi(bob.c_str());
    srand(seed);
    int tileType = rand() % 4+1;
    switch(tileType){
        case 1:
            return "lake";
        case 2:
            return "mountain";
        case 3:
            return "rugged";
        case 4:
            return "plain";
        default: return "ABORT!";
    }
}
