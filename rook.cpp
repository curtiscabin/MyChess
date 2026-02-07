#include "rook.h"

Rook::Rook(QWidget*parent, QColor color) : Chess(parent, color){}

bool Rook::move_chess(Ceil *a, Ceil *b)
{
    if(a==b)return false;

    if(a->distToByCol(b) * a->distToByRow(b) == 0)
    {
        qDebug()<<"after first check of rook";
        WayChecker wayCheck;
        if(!wayCheck.onBoardIsWayFromToClear(a,b,a->parentWidget()))
            return false;
        qDebug()<<"after wayCheck of rook";

        if(b->getChess()){
            if(possibility_cutting(a, b))
                cut_chess(b);
            else
                return false;
        }
        else{
            setParent(b);
        }

        raise();
        show();
        qDebug()<<"over move_chess";
        return true;
    }
    else return false;
}

void Rook::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    int side = qMin(width(), height());
    painter.translate(width() / 2, height() / 2);

    double scaleFactor = (side / 100.0) * 0.85;
    painter.scale(scaleFactor, scaleFactor);

    QPen pen(Qt::black, 6);
    pen.setJoinStyle(Qt::RoundJoin);
    pen.setCapStyle(Qt::RoundCap);
    painter.setPen(pen);
    painter.setBrush(color);

    QPainterPath tower;
    tower.moveTo(-20, -42);
    tower.lineTo(-20, -25);
    tower.lineTo(20, -25);
    tower.lineTo(20, -42);

    tower.lineTo(12, -42);
    tower.lineTo(12, -34);
    tower.lineTo(4, -34);
    tower.lineTo(4, -42);
    tower.lineTo(-4, -42);
    tower.lineTo(-4, -34);
    tower.lineTo(-12, -34);
    tower.lineTo(-12, -42);
    tower.closeSubpath();
    painter.drawPath(tower);

    painter.drawRect(-22, -25, 44, 8);

    QPainterPath body;
    body.moveTo(-16, -17);
    body.quadTo(-12, 15, -24, 35);
    body.lineTo(24, 35);
    body.quadTo(12, 15, 16, -17);
    body.closeSubpath();
    painter.drawPath(body);

    painter.drawRect(-30, 35, 60, 10);
}
