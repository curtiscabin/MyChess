#ifndef QUEEN_H
#define QUEEN_H

#include "chess.h"

class Queen : public Chess
{
    Q_OBJECT
public:
    Queen(QWidget*parent, QColor color);

    void paintEvent(QPaintEvent* event) override;

    bool pathway_rule(Ceil *a, Ceil *b) override;
};

#endif // QUEEN_H
