#include "ceil.h"

Ceil::Ceil(const QColor &color, const QPoint&p, QWidget *parent) : QPushButton(parent)
{
    this->setStyleSheet(QString("background-color: %1;").arg(color.name()));
    this->setFixedSize(50,50);
    this->move(p);
    this->show();
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
    if(!getChess())return;

    delete getChess();
    clearChess();
    update();
}


int Ceil::distTo(Ceil *b)
{
    //bishop
    if(abs(b->getRow() - getRow()) == abs(b->getCol() - getCol())){
        return abs(b->getRow() - getRow());
    }
    //rook
    else{
        if(b->getRow() - getRow() == 0){
            return abs(b->getCol() - getCol());
        }
        else return abs(b->getRow() - getRow());
    }
}

bool Ceil::isOccupiedByChess()
{
    return currentChess;
}


