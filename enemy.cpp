#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <QDebug>
#include <stdlib.h>
#include "Player.h"
#include "game.h"
#include <QMediaPlayer>

extern Game * game; //postoji externi globalni objekt
int height = 0;
int enemyPair = 0;

Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){


    //postavljanje random pozicije
    if(enemyPair==0){
      setPixmap(QPixmap(":/img/enemy.png"));
      height = (rand() % 450)-550;
      enemyPair++;
    }
    else
    {
        height+=  (rand() % 70)+670;;
        enemyPair=0;
        setPixmap(QPixmap(":/img/enemy2.png"));
    }

    setPos(400,height );
    //povezivanje na timer
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(10);
}

void Enemy::move(){
    QList<QGraphicsItem *> colliding_items=collidingItems(); //ova memberfunkcija će vratit listu pojntera svih qgraphic itema s kojima se pozivajući objekt kolidira pa ćemo proći listu i vidjeti ima li sudara
    for (int i = 0, n = colliding_items.size(); i<n; ++i){

        if (typeid(*(colliding_items[i]))== typeid(Player)){
            //scene()->removeItem(colliding_items[i]);

            game->gtimer->stop();
            game->musicStop();
            QMediaPlayer * dieSound = new QMediaPlayer();
            dieSound->setMedia(QUrl("qrc:/snd/die.wav")); //qurl za acces fileu)
            dieSound->play();

            scene()->removeItem(this);
            delete this;
            return;
        }
    }


    //pomakni neprijatelja
    setPos(x()-1.37 ,y());
    if(pos().x()<-55){
           scene()->removeItem(this);
          delete this;
}
}
