#ifndef KNIGHT_H
#define KNIGHT_H

#include "chess.h"

class Knight : public Chess
{
    Q_OBJECT
public:
    Knight(QWidget*parent, QColor color);

    bool move_chess(Ceil *a, Ceil *b) override;

    void paintEvent(QPaintEvent* event) override;
};

#endif // KNIGHT_H
