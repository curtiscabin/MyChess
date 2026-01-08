#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include "chess.h"
#include "ceil.h"
#include "pawn.h"
#include"QLabel"

class Board : public QWidget
{
    Q_OBJECT

    QVector<Chess*> white_chess, black_chess;
    QVector<QVector<Ceil*>> ceils;

    QColor getColorForCeil(const int&i, const int&j);

    QPoint getPointForCeil(const int&i, const int&j);

    void CreateChess(const int&i, const int&j, Ceil*ceil);

    bool isNecessarySetChess(const int&i);

    void handleCeilClick(int i, int j);
public:
    explicit Board(QWidget *parent = nullptr);

    void filling_ceils();

signals:
};

#endif // BOARD_H
