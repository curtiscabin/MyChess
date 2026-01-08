#include "ceil.h"

Ceil::Ceil(const QColor &color, const QPoint&p, QWidget *parent) : QPushButton(parent)
{
    this->setStyleSheet(QString("background-color: %1;").arg(color.name()));
    this->setFixedSize(50,50);
    this->move(p);
    this->show();
}

bool Ceil::isOccupiedByChess()
{
    return currentChess;
}

Chess *Ceil::getChess()
{
    return currentChess;
}

void Ceil::setChess(Chess* chess)
{
    currentChess = chess;
}

void Ceil::clearChess()
{
    currentChess = nullptr;
}

int Ceil::getRow()
{
    return y() / 50;
}

int Ceil::getCol()
{
    return x() / 50;
}

void Ceil::deleteChess()
{
    if(!isOccupiedByChess())return;

    delete getChess();
    clearChess();
    update();
}



