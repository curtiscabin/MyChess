#include "king.h"
#include "checkmatechecker.h"

King::King(QWidget*parent, QColor color) : Chess(parent, color){}

bool King::move_chess(Ceil *a, Ceil *b)
{
    qDebug()<<"king moves";
    if(a->distToByCol(b) > 1 || a->distToByRow(b) > 1) return false;

    CheckMateChecker CheckMateCheck;

    if(CheckMateCheck.CheckChecker(a, b, b->parentWidget())) return false;
    qDebug()<<"after CheckMateChecker";

    if(b->getChess()){
        if(possibility_cutting(b))
            cut_chess(b);
        else
            return false;
    }
    else{
        setParent(b);
    }

    raise();
    show();
    return true;
}

void King::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QPen crossPen(Qt::black, 2.5);
    crossPen.setJoinStyle(Qt::RoundJoin);
    crossPen.setCapStyle(Qt::RoundCap);

    QPen normalPen(Qt::black, 2);
    normalPen.setJoinStyle(Qt::RoundJoin);
    normalPen.setCapStyle(Qt::RoundCap);

    painter.setBrush(this->color);

    painter.setPen(crossPen);
    painter.drawLine(25, 8, 25, 15);
    painter.drawLine(21, 11, 29, 11);
    painter.drawEllipse(QPointF(25, 7), 2, 2);

    painter.setPen(normalPen);

    painter.drawEllipse(QPointF(25, 19), 4.5, 4.5);

    painter.drawRect(21, 24, 8, 3);

    QPainterPath body;
    body.moveTo(21, 27);
    body.quadTo(19, 34, 17, 40);
    body.lineTo(33, 40);
    body.quadTo(31, 34, 29, 27);
    body.closeSubpath();
    painter.drawPath(body);

    painter.drawRect(16, 40, 18, 3);
    painter.drawRect(12, 43, 26, 3);
}
