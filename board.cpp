#include "board.h"

Board::Board(QWidget *parent)
    : QWidget{parent}
{}

QColor Board::getColorForCeil(const int &i, const int &j)
{
    if((i+j)%2 == 0)return "#D38753";
    else return "#221411";
}

QPoint Board::getPointForCeil(const int &i, const int &j)
{
    int x = j * 50;
    int y = i * 50;

    return QPoint(x,y);
}

void Board::CreateChess(const int &i, const int &j, Ceil *ceil)
{
    Chess* chess = nullptr;
    QColor color = (i <= 1) ? QColor("#77716A") : QColor("#ffffff");

    if (i == 1 || i == 6) {
        chess = new Pawn(ceil, color);
    }
    else if(j == 0 || j == 7){
        //rook
    }

    ceil->setChess(chess);
    if(color == "#77716A")black_chess.push_back(chess);
    else white_chess.push_back(chess);
}

bool Board::isNecessarySetChess(const int &i)
{
    if (i<=1 || i >= 6) return true;
    return false;
}

void Board::handleCeilClick(int i, int j)
{
    Ceil*ceil = ceils[i][j];
    qDebug()<<i<<j;
}

void Board::filling_ceils()
{
    for(int i = 0 ;i<8;i++){
        ceils.push_back(QVector<Ceil*>());
        for(int j = 0; j<8;j++){
            Ceil* ceil = new Ceil(getColorForCeil(i,j), getPointForCeil(i,j),this);
            ceils.back().push_back(ceil);

            connect(ceil, &Ceil::clicked, this, [this, i, j]() {
                handleCeilClick(i, j);
            });

            if(isNecessarySetChess(i)){
                qDebug()<<i<<j;
                CreateChess(i,j,ceil);

            }

            // QString test = QString::number(i) + " " + QString::number(j);
            // QLabel* label = new QLabel(test, ceil);
            // label->move(25,25);
        }
    }
}
