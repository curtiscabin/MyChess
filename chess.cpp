#include "chess.h"

Chess::Chess(QWidget *parent, QColor color)
    : QWidget{parent}, color(color)
{
    setFixedSize(50,50);
    move(0,0);
    show();
}

bool Chess::move_chess(Ceil *a, Ceil *b)
{
    if(possibility_move(a,b))
    {

        if(possibility_cutting(b)){
            cut_chess(b);
        }
        else {
            setParent(b);
        }

        raise();
        show();
        qDebug()<<"over move_chess";
        return true;
    }
    else return false;
}

bool Chess::possibility_move(Ceil *a, Ceil *b)
{
    if(a==b)return false;

    if(!pathway_rule(a,b)) return false;

    Chess*maybe_chess = b->getChess();

    if(maybe_chess && color==maybe_chess->getColor()){
        return false;
    }

    WayChecker wayCheck;

    return wayCheck.onBoardIsWayFromToClear(a,b,a->parentWidget());
}

void Chess::cut_chess(Ceil *b)
{
    b->getChess()->hide();
    b->deleteChess();
    setParent(b);
}

bool Chess::possibility_cutting(Ceil *b)
{
    Chess* enemy = b->getChess();

    return enemy && color!=enemy->getColor();
}

QColor Chess::getColor()
{
    return color;
}


