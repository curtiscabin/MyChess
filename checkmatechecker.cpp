#include "checkmatechecker.h"
#include "board.h"
#include "ceil.h"
#include "waychecker.h"

CheckMateChecker::CheckMateChecker() {}

bool CheckMateChecker::CheckChecker(Ceil*king_ceil, Ceil *from, QWidget *board1)
{

    Board*board = dynamic_cast<Board*>(board1);
    bool isCheck = false;
    WayChecker wayCheck;

    QVector<QVector<Ceil*>> ceils = board->getVectorCeils();

    for(int i = 0; i < ceils.size(); i++){
        for(int j = 0; j < ceils[0].size(); j++){
            Ceil*ceil = ceils[i][j];
            if(ceil->getChess() && ceil->getChess()->getColor()!=king_ceil->getChess()->getColor()){
                qDebug()<<"go to wayCheck in CheckChecker";
                if(wayCheck.onBoardIsWayFromToClear(ceil, from, board1)){
                    isCheck = true;
                }
                if(isCheck) return true;
            }
        }
    }

    return false;

}
