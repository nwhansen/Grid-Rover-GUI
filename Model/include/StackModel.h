/* 
 * File:   StackModel.h
 * Author: Nathan Hansen
 *
 * Created on March 27, 2012, 1:35 PM
 */

#ifndef STACKMODEL_H
#define	STACKMODEL_H
#include "AbstractModel.h"
#include "StackConsequence.h"
#include "StackTile.h"
#include <stdlib.h>
#include <queue>

namespace StackModelNameSpace {


    class StackModel : public AbstractModelNameSpace::AbstractModel {
    public:

        /**
         * Constructs a none threaded stack model Map. If the width or height is less than 10 it defaults to 10.
         * @param width how wide?
         * @param height how tall?
         */
        StackModel(int width, int height);

        StackModel(const StackModel& orig);

        virtual ~StackModel();

        StackConsequence * sufferConsequence();

        StackTile * getTileInfo(int XoffSet, int YoffSet);
    private:
        // A max heap queue. We need a min heap.
        std::priority_queue< StackConsequence, std::vector<StackConsequence>, std::greater<StackConsequence> > EventQueue;
        int Width, Height;
        StackTile **Map;
    };



}
#endif	/* STACKMODEL_H */

