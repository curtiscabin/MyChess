#ifndef ROOK_H
#define ROOK_H

#include "chess.h"

class Rook : public Chess
{
    Q_OBJECT
public:
    Rook(QWidget*parent, QColor color);

    void paintEvent(QPaintEvent* event) override;

    bool pathway_rule(Ceil *a, Ceil *b) override;
 };

#endif // ROOK_H
