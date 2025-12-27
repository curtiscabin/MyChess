#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include "chess.h"
#include "ceil.h"

class Board : public QWidget
{
    Q_OBJECT

    QVector<Chess*> chess;
    QVector<QVector<Ceil*>> ceils;

    QColor getColor(const int&i, const int&j);

    QPoint getPointForCeil(const int&i, const int&j);
public:
    explicit Board(QWidget *parent = nullptr);

    void filling_ceils();

signals:
};

#endif // BOARD_H
