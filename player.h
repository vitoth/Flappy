#ifndef PLAYER
#define PLAYER

#define PLWIDTH 30
#define PLHEIGHT 30
#include <QGraphicsPixmapItem>
//2 stvari koje moramo osigurati da bi objekt mogao hendalati signals i slots
//1. stvar da object inherita iz QObject pa ga moramo includati

#include <QObject>

#include <QMediaPlayer>

class Player: public QObject, public QGraphicsPixmapItem{
    //moramo includati q_objcet macro ovdje
    Q_OBJECT //sad može hendlati signals  i slots
private:
    QMediaPlayer * flapSound;
    QMediaPlayer * hitSound;
public:
    Player(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event);
	QTimer * flapTimer = nullptr;
	QTimer * fallTimer = nullptr;
	int spawnDelay = 0;
	int flapHeight = 0;
	int rel_y;
	bool flapInProgress;
	int aft_y;
	double j = 0;
	int move = 3;
    double result;
    double param = 20;
    int ppos;
    int ydelta = 0;
    double fallm=2.2;
    int increase = 0;
    void scoreReset();

public slots:
    void Game(); //spawn slot je spojen na timer
    void flap();
    void flapReset();
	void fall();
};

#endif // PLAYER

