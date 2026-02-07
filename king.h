#ifndef KING_H
#define KING_H

#include "chess.h"

class King : public Chess
{
    Q_OBJECT
public:
    King(QWidget*parent, QColor color);

    void paintEvent(QPaintEvent* event) override;

    bool pathway_rule(Ceil *a, Ceil *b) override;

    bool possibility_move(Ceil *a, Ceil *b) override;
};

#endif // KING_H
