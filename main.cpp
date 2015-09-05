#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QTimer>
#include <QDebug>
#include "game.h"


Game * game;
int main(int argc, char *argv[])
{


    QApplication a(argc, argv);

    game = new Game();

    return a.exec();
}
