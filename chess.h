#ifndef CHESS_H
#define CHESS_H

#include <QWidget>
#include <QPainterPath>
#include "ceil.h"
#include "waychecker.h"

class Chess : public QWidget
{
    Q_OBJECT
protected:
    QColor color;
public:
    explicit Chess(QWidget *parent, QColor color);

    virtual bool move_chess(Ceil *a, Ceil *b) = 0;

    virtual bool possibility_move(Ceil *a, Ceil *b);

    void cut_chess(Ceil* b);

    virtual bool possibility_cutting(Ceil *a, Ceil* b);

    QColor getColor();

signals:
};

#endif // CHESS_H
