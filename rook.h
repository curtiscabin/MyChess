#ifndef ROOK_H
#define ROOK_H

#include "chess.h"

class Rook : public Chess
{
    Q_OBJECT
public:
    Rook(QWidget*parent, QColor color);

    bool move_chess(Ceil *a, Ceil *b) override;

    void paintEvent(QPaintEvent* event) override;
};

#endif // ROOK_H
