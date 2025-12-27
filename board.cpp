#include "board.h"

QColor Board::getColor(const int &i, const int &j)
{
    if((i+j)%2 == 0)return "#D38753";
    else return "#221411";
}

QPoint Board::getPointForCeil(const int &i, const int &j)
{
    int x = i * 50;
    int y = j * 50;

    return QPoint(x,y);
}

Board::Board(QWidget *parent)
    : QWidget{parent}
{}

void Board::filling_ceils()
{
    for(int i = 0 ;i<8;i++){
        ceils.push_back(QVector<Ceil*>());
        for(int j = 0; j<8;j++){
            Ceil* ceil = new Ceil(getColor(i,j), getPointForCeil(i,j),this);
            ceils.back().push_back(ceil);
        }
    }
}
