#ifndef DUMMYMODEL_H
#define DUMMYMODEL_H

#include <string>
#include <stdlib.h>


enum TileType {
    Lake, Plain, Mountain, Rugged
};
class DummyModel
{
public:
    DummyModel();

    /**
      * Get a tile located at X and Y.
      *
      */
    TileType getTile(int x, int y);

private:
    //Random Numbers

    //
};


#endif // DUMMYMODEL_H
