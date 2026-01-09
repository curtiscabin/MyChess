#ifndef QUEEN_H
#define QUEEN_H

#include "chess.h"

class Queen : public Chess
{
    Q_OBJECT
public:
    Queen(QWidget*parent, QColor color);

    bool move_chess(Ceil *a, Ceil *b) override;

    void paintEvent(QPaintEvent* event) override;
};

#endif // QUEEN_H
