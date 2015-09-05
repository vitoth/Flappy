#ifndef SCORE
#define SCORE

#include <QGraphicsTextItem>

class Score: public QGraphicsTextItem{
public:
    Score(QGraphicsItem * parent = 0);
    void increase();
    void reset();
    int getScore();
    int score;
private:
};

#endif // SCORE

