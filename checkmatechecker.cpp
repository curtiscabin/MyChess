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
            Chess*chess = ceil->getChess();
            if(chess && chess->getColor()!=king_ceil->getChess()->getColor()){
                qDebug()<<"go to wayCheck in CheckChecker";
                if(chess->possibility_move(ceil, from)){
                    isCheck = true;
                }
                if(isCheck) return true;
            }
        }
    }

    return false;

}
