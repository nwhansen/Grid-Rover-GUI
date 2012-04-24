/****************************************************************************
**
** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the demonstration applications of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "mainwindow.h"
#include "view.h"

#include "Tile.h"

#include <QtGui>
#include <iostream>
#include "Rover.h"

String empty("");
String physobjs("Model/Data/physical_objects.xml");
String errlog("error.log");
String msglog("messages.log");
String rvrprog("./blah.sh");

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    scene = new QGraphicsScene;
    roverX = 530;
    roverY = 530;

    View *view = new View("World");
    view->view()->setScene(scene);
    connect(view->refreshButton, SIGNAL(clicked()), this, SLOT(reloadMap()));
    //move the rover around using buttons
    connect(view->upButton, SIGNAL(clicked()), this, SLOT(moveRoverU()));
    connect(view->downButton, SIGNAL(clicked()), this, SLOT(moveRoverD()));
    connect(view->rightButton, SIGNAL(clicked()), this, SLOT(moveRoverR()));
    connect(view->leftButton, SIGNAL(clicked()), this, SLOT(moveRoverL()));


    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(view);
    setLayout(layout);

    setWindowTitle(tr("Grid Rover Map Viewer"));

    engine = new Engine(10, 10, rvrprog, physobjs, errlog, msglog, empty, empty);

    roverObj = engine->GetRover(0);

    populateScene(10,10);
}



/**
  * Main code to populate the tiles of the main window. Stitching time baby.
  * Assumes all tiles provided are of the same height and width.
  */
void MainWindow::populateScene(int width, int height)
{
    //Needs to interact with model to get tile types and location.

    QPixmap lake(":/lake"), plain(":/plain"),
            mountain(":/mountain"), rugged(":/rugged"), rover(":/rover");
    QGraphicsPixmapItem *item = NULL;
    //Build maps from bottom left corner to top right corner
    for(int w = 0; w < width; w++){
        for(int h = 0; h < height; h++){
            Tile* tile = engine->getTileInfo(w,h);
            switch(tile->getTileType()){
                case Mountain:
                    item = new QGraphicsPixmapItem(mountain);
                    break;
                case Lake:
                    item = new QGraphicsPixmapItem(lake);
                    break;
                case Plain:
                    item = new QGraphicsPixmapItem(plain);
                    break;
                case Rugged:
                    item = new QGraphicsPixmapItem(rugged);
                    break;
                default:
                    std::cerr << "Unexpected Tile selected! correct code";
                    item = NULL;
            }
            item->setPos(QPointF(w * lake.width(), h * mountain.height()));
            scene->addItem(item);

            for(TileIterator i = tile->begin(); i!=tile->end(); ++i){
                if((*i) == roverObj)
                {
                    roverX = roverObj->GetXCoord() * 100;
                    roverY = roverObj->GetYCoord() * 100;
                    placeRover();
                }
            }
        }
    }

    //placeRover();
    /*QGraphicsPixmapItem *item = new QGraphicsPixmapItem(image);
    item->setPos(QPointF(0, 0));

    scene->addItem(item);

    return;
    // Populate scene
    int xx = 0;
    int nitems = 0;
    for (int i = -11000; i < 11000; i += 110) {
        ++xx;
        int yy = 0;
        for (int j = -7000; j < 7000; j += 70) {
            ++yy;
            qreal x = (i + 11000) / 22000.0;
            qreal y = (j + 7000) / 14000.0;
            QGraphicsPixmapItem *item = new QGraphicsPixmapItem(image);
            item->setPos(QPointF(i, j));
            scene->addItem(item);

            ++nitems;
        }
    }*/
}

void MainWindow::reloadMap(){
    if (engine->gameInProgress()) {
        engine->next();
        if (engine->gameInProgress()) {
            QList<QGraphicsItem*> list = scene->items();
            for(int i = 0; i < list.size(); i++){
                QGraphicsItem* item = list.at(i);
                scene->removeItem(item);
                delete item;
            }
            populateScene(10,10);
        }
    }
}

void MainWindow::placeRover(){
    QPixmap roverPic(":/rover");
    rover = new QGraphicsPixmapItem(roverPic);
    rover->setPos(QPointF(roverX,roverY));
    scene->addItem(rover);
}
void MainWindow::moveRoverU() {
    roverX = roverX;
    if(roverY>=100)
        roverY = roverY-100;
    rover->setPos(QPointF(roverX,roverY));
}

void MainWindow::moveRoverD() {
    roverX = roverX;
    if(roverY<=900)
    roverY = roverY+100;
    rover->setPos(QPointF(roverX,roverY));
}

void MainWindow::moveRoverL() {
    if(roverX>=100)
        roverX = roverX-100;
    roverY = roverY;
    rover->setPos(QPointF(roverX,roverY));
}

void MainWindow::moveRoverR() {
    if(roverX<=900)
        roverX = roverX+100;
    roverY = roverY;
    rover->setPos(QPointF(roverX,roverY));
}

