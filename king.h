#ifndef KING_H
#define KING_H

#include "chess.h"

class King : public Chess
{
    Q_OBJECT
public:
    King(QWidget*parent, QColor color);

    bool move_chess(Ceil *a, Ceil *b) override;

    void paintEvent(QPaintEvent* event) override;
};

#endif // KING_H
