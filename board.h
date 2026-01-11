#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include"QLabel"
#include "chess.h"
#include "ceil.h"
#include "pawn.h"
#include "rook.h"
#include "bishop.h"
#include "king.h"
#include "knight.h"
#include "queen.h"

class Board : public QWidget
{
    Q_OBJECT

    QVector<Chess*> white_chess, black_chess;
    QVector<QVector<Ceil*>> ceils;
    Ceil*firstClick = nullptr;

    QColor getColorForCeil(const int&i, const int&j);

    QPoint getPointForCeil(const int&i, const int&j);

    void CreateChess(const int&i, const int&j, Ceil*ceil);

    bool isNecessarySetChess(const int&i);

    void handleCeilClick(int i, int j);

    Ceil* getNeighbourTo(Ceil*a, Ceil*b);
public:
    explicit Board(QWidget *parent = nullptr);

    void filling_ceils();

    bool onBoardIsWayFromToClear(Ceil *a, Ceil* b);

signals:
};

#endif // BOARD_H
