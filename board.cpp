#include "board.h"

Board::Board(QWidget *parent)
    : QWidget{parent}
{}

QColor Board::getColorForCeil(const int &i, const int &j)
{
    if((i+j)%2 == 0)return "#D38753";
    else return "#7B344C";
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
        chess = new Rook(ceil, color);
    }
    else if(j == 1 || j == 6){
        chess = new Knight(ceil, color);
    }
    else if(j == 2 || j == 5){
        chess = new Bishop(ceil, color);
    }
    else if(j == 3){
        chess = new Queen(ceil, color);
    }
    else if(j == 4){
        chess = new King(ceil, color);
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

bool Board::onBoardIsWayFromToClear(Ceil *a, Ceil *b)
{
    //bishop
    if(b->getRow() - a->getRow() == b->getCol() - a->getCol()){

    }
    //rook
    else{
        if(a->distTo(b) == 1){
            return true;
        }
        Ceil* neighbour = getNeighbourTo(a,b);
        if(neighbour->getChess()){
            return false;
        }
        else{
            return (neighbour, b);
        }
    }
}

void Board::handleCeilClick(int i, int j)
{
    Ceil*ceil = ceils[i][j];
    qDebug()<<i<<j;

    if(!ceil->isOccupiedByChess() && !firstClick)return;

    if(!firstClick){
        firstClick = ceil;
        return;
    }
    else{
        qDebug()<<"enter to go to move_chess";
        if(firstClick->getChess()->move_chess(firstClick, ceil)){
            qDebug()<<"successful move";
            ceil->setChess(firstClick->getChess());
            firstClick->clearChess();
        }

        firstClick = nullptr;
    }
}

Ceil *Board::getNeighbourTo(Ceil *a, Ceil *b)
{
    QVector<int>vec_to_b;
    vec_to_b.push_back(b->getRow() - a->getRow());
    vec_to_b.push_back(b->getCol() - a->getCol());

    if(vec_to_b[0] != 0)vec_to_b[0]/=vec_to_b[0];
    if(vec_to_b[1] != 0)vec_to_b[1]/=vec_to_b[1];

    return ceils[a->getRow() + vec_to_b[0]][a->getCol() + vec_to_b[1]];
}
