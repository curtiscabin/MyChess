#include "pawn.h"

Pawn::Pawn(QWidget*parent, QColor color) : Chess(parent, color){}

bool Pawn::move_chess(Ceil *a, Ceil *b)
{
    if((b->getRow() - a->getRow() > 2 || b->getRow() - a->getRow() < 0 && color == "#77716A") || (a->getRow() - b->getRow() > 2 || a->getRow() - b->getRow() < 0 && color == "#ffffff") || abs(b->getCol() - a->getCol()) > 1)return false;

    //cut maybe
    if(abs(b->getCol() - a->getCol()) == 1 && (b->getRow() - a->getRow() == 1 && color == "#77716A" || b->getRow() - a->getRow() == -1 && color == "#ffffff")){
        if(!b->isOccupiedByChess())return false;

        b->getChess()->hide();
        b->deleteChess();
        setParent(b);
    }
    //step forward
    else if(abs(b->getRow() - a->getRow()) == 1 || (abs(b->getRow() - a->getRow()) == 2 && firstStep)){
        if(b->isOccupiedByChess())return false;

        setParent(b);
    }


    if(firstStep)firstStep = false;
    raise();
    show();
    return true;
}

void Pawn::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    int side = qMin(width(), height());
    painter.translate(width() / 2, height() / 2);

    double scaleFactor = (side / 100.0) * 0.85;

    painter.scale(scaleFactor, scaleFactor);

    QPen pen(Qt::black, 6);
    pen.setJoinStyle(Qt::MiterJoin);
    pen.setCapStyle(Qt::RoundCap);
    painter.setPen(pen);
    painter.setBrush(color);

    painter.drawEllipse(QPointF(0, -28), 16, 16);

    painter.drawRect(-18, -10, 36, 8);

    QPainterPath body;
    body.moveTo(-12, -2);
    body.quadTo(-8, 15, -22, 35);
    body.lineTo(22, 35);
    body.quadTo(8, 15, 12, -2);
    body.closeSubpath();
    painter.drawPath(body);

    painter.drawRect(-30, 35, 60, 10);
}
