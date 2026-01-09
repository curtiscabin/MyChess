#ifndef BISHOP_H
#define BISHOP_H

#include "chess.h"

class Bishop : public Chess
{
    Q_OBJECT
public:
    Bishop(QWidget*parent, QColor color);

    bool move_chess(Ceil *a, Ceil *b) override;

    void paintEvent(QPaintEvent* event) override;
};

#endif // BISHOP_H
