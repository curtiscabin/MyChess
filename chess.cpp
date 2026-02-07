#include "chess.h"

Chess::Chess(QWidget *parent, QColor color)
    : QWidget{parent}, color(color)
{
    setFixedSize(50,50);
    move(0,0);
    show();
}

bool Chess::possibility_move(Ceil *a, Ceil *b)
{
    return true;
}

void Chess::cut_chess(Ceil *b)
{
    b->getChess()->hide();
    b->deleteChess();
    setParent(b);
}

bool Chess::possibility_cutting(Ceil* a,Ceil *b)
{
    Chess* enemy = b->getChess();

    return color!=enemy->getColor();
}

QColor Chess::getColor()
{
    return color;
}


