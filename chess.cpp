#include "chess.h"

Chess::Chess(QWidget *parent, QColor color)
    : QWidget{parent}, color(color)
{
    setFixedSize(50,50);
    move(0,0);
    show();
}


