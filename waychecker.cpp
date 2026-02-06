#include "waychecker.h"
#include "board.h"
#include "ceil.h"

WayChecker::WayChecker() {}

bool WayChecker::onBoardIsWayFromToClear(Ceil *a, Ceil *b, QWidget* board1)
{
    Board*board = dynamic_cast<Board*>(board1);
    if(a->distTo(b) == 1){
        return true;
    }
    Ceil* neighbour = board->getNeighbourTo(a,b);
    qDebug()<<"getted neighbour";
    if(neighbour->getChess()){
        return false;
    }
    else{
        qDebug()<<"recursive waychecker";
        return onBoardIsWayFromToClear(neighbour, b, board1);
    }
}
