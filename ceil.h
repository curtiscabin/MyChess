#ifndef CEIL_H
#define CEIL_H

#include <QPushButton>
#include <QColor>
#include<QPainter>

class Chess;

class Ceil;

class Board {
public:
    bool onBoardIsWayFromToClear(Ceil* a, Ceil* b);
};

class Ceil : public QPushButton
{
    Q_OBJECT

    Chess* currentChess = nullptr;
public:
    Ceil(const QColor &color,const QPoint& p,QWidget*parent);

    Chess* getChess();

    void setChess(Chess* chess);

    void clearChess();

    int getRow();

    int getCol();

    void deleteChess();

    bool isWayFromToClear(Ceil *b);

    int distTo(Ceil*b);
};

#endif // CEIL_H
