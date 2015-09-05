#include "score.h"
#include <QFont>
#include <QFontDatabase>
#include <QDebug>
#include <QFontInfo>
#include "player.h"
Score::Score(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    score = 0;
    QFontDatabase database;
    int result = database.addApplicationFont(":/snd/flappy.TTF");
    setPlainText( QString::number(score));
    QFont f = database.font("MS Shell Dlg 2", "normal", 30);
    setFont(f);
}

void Score::increase()
{
    score++;

    setPlainText( QString::number(score));
}
void Score::reset()
{
    score=0;
    setPlainText( QString::number(score));

}



int Score::getScore()
{
    return score;
}
