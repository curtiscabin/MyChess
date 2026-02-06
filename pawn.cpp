#include "pawn.h"

Pawn::Pawn(QWidget*parent, QColor color) : Chess(parent, color){}

bool Pawn::move_chess(Ceil *a, Ceil *b)
{
    if((b->getRow() - a->getRow() > 2 || b->getRow() - a->getRow() < 0 && color == "#77716A")
        ||
        (a->getRow() - b->getRow() > 2 || a->getRow() - b->getRow() < 0 && color == "#ffffff")
        ||
        a->distToByCol(b) > 1)
        return false;

    //cut maybe
    if(a->distToByCol(b) == 1 && (b->getRow() - a->getRow() == 1 && color == "#77716A" || b->getRow() - a->getRow() == -1 && color == "#ffffff")){
        if(b->getChess() && possibility_cutting(b))
            cut_chess(b);
        else
            return false;
    }
    //step forward
    WayChecker wayCheck;
    if(a->distToByRow(b) == 1 || (a->distToByRow(b) == 2 && firstStep && wayCheck.onBoardIsWayFromToClear(a, b, b->parentWidget()))){
        if(b->getChess())return false;

        setParent(b);
    }
    else return false;


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
