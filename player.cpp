
#include "player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "enemy.h"
#include <QTimer>
#include <math.h> 
#include <game.h> 
#include <QDebug>
#include <stdlib.h> 
#include <QMediaPlayer>
#include <QMovie>
#include <QLabel>
#include "score.h"


#define PI 3.14159265
extern Game * game;
Player::Player(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    hitSound = new QMediaPlayer();
    hitSound->setMedia((QUrl("qrc:/snd/hit.wav")));
    flapSound = new QMediaPlayer();
    flapSound->setMedia((QUrl("qrc:/snd/flap.wav")));

    setPixmap(QPixmap(":/img/bird.gif"));
}

void Player::keyPressEvent(QKeyEvent *event){

    //uklonjen pomak gore na tipku
//	if (event->key() == Qt::Key_Up){
//		if (pos().y() - PLHEIGHT / 2 > 0)
//			setPos(x(), y() - 80);
//	}

    if (event->key() == Qt::Key_Space && !event->isAutoRepeat()){
        param = 0;
		delete fallTimer; fallTimer = nullptr;
		delete flapTimer;
		flapTimer = new QTimer();
		rel_y = pos().y();
		QObject::connect(flapTimer, SIGNAL(timeout()), this, SLOT(flap()));
        flapTimer->start(4);
        flapSound->setMedia(QUrl("qrc:/snd/flap.wav")); //qurl za acces fileu)
        flapSound->play();
	}
   else if (event->key() == Qt::Key_N && !event->isAutoRepeat()){

        Player::scoreReset();
       game->score->reset();
       game->gtimer->start();
       this->setPos(100,100);
       game->musicStart();
    }

    //uklonjen pomak dolje na tipku
//	else if (event->key() == Qt::Key_Down){
//		if (pos().y() + 60 < 600)
//			setPos(x(), y() + 30);
//	}
}

void Player::Game(){

    if(musicCounter++ == 596){
    game->musicStart();
    musicCounter=0;
    }
    //stvaranje neprijatelja
	spawnDelay++;
	if (spawnDelay == 400)
    {
		Enemy * enemy = new Enemy();
		scene()->addItem(enemy);
        Enemy * enemy2 = new Enemy();
        scene()->addItem(enemy2);
        if(increase++ > 0)
        {
            game->score->increase();
        hitSound->play();
        }

		spawnDelay = 0;
	}
}
void Player::flap(){

    fallm=2.2;
    param++;
    result = sin(param*PI / 180) * 57;
	aft_y = rel_y - result;
	setPos(x(), aft_y);
	aft_y = pos().y();
    if (param > 159 || pos().y()<-20)
	{
		flapReset();
		fall();
	}
}

void Player::flapReset()
{
	delete flapTimer;
	flapTimer = nullptr;
    param = 1;
	fallTimer = new QTimer();
	QObject::connect(fallTimer, SIGNAL(timeout()), this, SLOT(fall()));
	fallTimer->start(4);
}
void Player::scoreReset()
{
    increase = 0;
}

void Player::fall()
{



	rel_y = pos().y();
	setPos(x(), aft_y);
    fallm+=0.008;
    aft_y = rel_y + fallm;
	ppos = pos().y();
	if (ppos > WHEIGHT - PLHEIGHT)
	{
        delete fallTimer;
		fallTimer = nullptr;
        fallm=2.2;
	}
}
