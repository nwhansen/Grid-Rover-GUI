#ifndef DUMMYMODEL_H
#define DUMMYMODEL_H

#include <string>
#include <stdlib.h>


class DummyModel
{
public:
    DummyModel();

    /**
      * Get a tile located at X and Y.
      *
      */
    std::string getTile(int x, int y);

private:
    //Random Numbers

    //
};

#endif // DUMMYMODEL_H
