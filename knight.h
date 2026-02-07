#ifndef KNIGHT_H
#define KNIGHT_H

#include "chess.h"

class Knight : public Chess
{
    Q_OBJECT
public:
    Knight(QWidget*parent, QColor color);

    void paintEvent(QPaintEvent* event) override;

    bool pathway_rule(Ceil *a, Ceil *b) override;

    bool possibility_move(Ceil *a, Ceil *b) override;
};

#endif // KNIGHT_H
