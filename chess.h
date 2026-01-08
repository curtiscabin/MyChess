#ifndef CHESS_H
#define CHESS_H

#include <QWidget>
#include <QPainterPath>
#include"ceil.h"

class Chess : public QWidget
{
    Q_OBJECT
protected:
    QColor color;
public:
    explicit Chess(QWidget *parent, QColor color);

    virtual bool move_chess(Ceil *a, Ceil *b) = 0;



signals:
};

#endif // CHESS_H
