#ifndef ENEMY
#define ENEMY

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include <QMediaPlayer>

class Enemy: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
private:
    QMediaPlayer * hitSound;
    public:
    QTimer * timer;
    Enemy(QGraphicsItem * parent=0);
public slots:
    void move();

};

#endif // ENEMY

