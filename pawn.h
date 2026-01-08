#ifndef PAWN_H
#define PAWN_H

#include "chess.h"

class Pawn : public Chess
{
    Q_OBJECT

    bool firstStep = true;
public:
    Pawn(QWidget*parent, QColor color);

    bool move_chess(Ceil *a, Ceil *b) override;

    void paintEvent(QPaintEvent* event) override;
};

#endif // PAWN_H
