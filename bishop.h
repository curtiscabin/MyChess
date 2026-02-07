#ifndef BISHOP_H
#define BISHOP_H

#include "chess.h"

class Bishop : public Chess
{
    Q_OBJECT
public:
    Bishop(QWidget*parent, QColor color);

    void paintEvent(QPaintEvent* event) override;

    bool pathway_rule(Ceil *a, Ceil *b) override;
};

#endif // BISHOP_H
