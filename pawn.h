#ifndef PAWN_H
#define PAWN_H

#include "chess.h"

class Pawn : public Chess
{
    Q_OBJECT

    bool firstStep = true;
public:
    Pawn(QWidget*parent, QColor color);

    bool possibility_move(Ceil *a, Ceil *b) override;

    bool move_chess(Ceil *a, Ceil *b) override;

    void paintEvent(QPaintEvent* event) override;

    bool possibility_cutting(Ceil *a, Ceil *b) override;
};

#endif // PAWN_H
