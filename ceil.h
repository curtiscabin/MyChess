#ifndef CEIL_H
#define CEIL_H

#include <QPushButton>
#include <QColor>
#include<QPainter>

class Chess;

class Ceil : public QPushButton
{
    Q_OBJECT

    Chess* currentChess = nullptr;
public:
    Ceil(const QColor &color,const QPoint& p,QWidget*parent);

    bool isOccupiedByChess();

    Chess* getChess();

    void setChess(Chess* chess);

    void clearChess();
};

#endif // CEIL_H
