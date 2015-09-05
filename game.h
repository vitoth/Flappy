#ifndef GAME
#define GAME
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "score.h"
#include "Player.h"

#define WWIDTH 400
#define WHEIGHT 600

class Game: public QGraphicsView{
public:
    Game(QWidget * parent=0);
    QMediaPlayer * music;
    QTimer * gtimer;
    void musicStart();
    void musicStop();
    QGraphicsScene * scene;
    Score * score;
};

#endif // GAME

