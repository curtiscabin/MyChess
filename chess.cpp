#include "chess.h"

Chess::Chess(QWidget *parent, QColor color)
    : QWidget{parent}, color(color)
{
    setFixedSize(50,50);
    move(0,0);
    show();
}

void Chess::cut_chess(Ceil *b)
{
    b->getChess()->hide();
    b->deleteChess();
    setParent(b);
}


