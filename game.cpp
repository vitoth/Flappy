#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "Enemy.h"
#include <QMediaPlayer>
#include "player.h"
#include "game.h"
#include <QImage>
#include <QBrush>
#include <QSound>



Game::Game(QWidget *parent){


    QGraphicsScene * scene = new QGraphicsScene();//stvaramo scenu

    scene->setSceneRect(0, 0, WWIDTH - 10, WHEIGHT - 10);
    QBrush *brush = new QBrush();
       brush->setStyle(Qt::SolidPattern); // Fix your problem !
       brush->setColor(QColor(200,243,255));
       scene->setBackgroundBrush(*brush);
    Player * player = new Player(); //stvaram item koji ću stavit u scenu


    player->setPos(100,100);//postavljamo poziciju i veličinu rectanglea
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);//dodajemo item u scenu

    score = new Score();
    scene->addItem(score);//dodajemo item u scenu





    QGraphicsView * view = new QGraphicsView(scene);//moramo doadti view da prikažemo nešto, i moramo reći koju scenu će vizualizirati, passamo mu pointer za scenu
    //imamo scenu imamo item i dodali smo ga u scenu i kreirali smo vieww da vizualiziramo scenu
    //view je widget a oni su po defaultu nevidljivi pa moramo reći da pokaže
    view->show();

    //opstavljanje viewa na fixnu veličinu
	view->setFixedSize(WWIDTH, WHEIGHT);
    //postavljanje scene, prva 2 vrijednosti gdje želimo scenu u odnosu na view, želimo točno na istom mjestu, zato 0,0


    //opizicironiranje ptice/plejera

    //stvaranje neprijateljea
    gtimer = new QTimer();
    QObject::connect(gtimer,SIGNAL(timeout()),player,SLOT(Game()));
    gtimer->start(5);


   musicStart();
}

void Game::musicStart()
{

     music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/snd/bgmusic.wav"));
    if(music->state() == QMediaPlayer::StoppedState)
        music->setPosition(0);
    music->play();


}

void Game::musicStop()
{

    music->stop();


}
