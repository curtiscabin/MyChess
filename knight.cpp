#include "knight.h"

Knight::Knight(QWidget*parent, QColor color) : Chess(parent, color){}

void Knight::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QPen pen(Qt::black, 2);
    pen.setJoinStyle(Qt::MiterJoin);
    pen.setCapStyle(Qt::RoundCap);
    painter.setPen(pen);
    painter.setBrush(this->color);

    QPainterPath base;
    base.moveTo(10, 45);
    base.lineTo(40, 45);
    base.lineTo(38, 40);
    base.lineTo(12, 40);
    base.closeSubpath();
    painter.drawPath(base);

    painter.drawRoundedRect(11, 35, 28, 5, 2, 2);

    QPainterPath body;
    body.moveTo(35, 35);

    body.cubicTo(38, 25, 36, 10, 25, 8);

    body.lineTo(23, 5);
    body.lineTo(20, 9);

    body.lineTo(12, 16);
    body.lineTo(8, 22);

    body.lineTo(11, 25);
    body.lineTo(13, 23);

    body.quadTo(25, 25, 15, 35);

    body.lineTo(35, 35);
    body.closeSubpath();

    painter.drawPath(body);
}

bool Knight::pathway_rule(Ceil *a, Ceil *b)
{
    return (a->distToByRow(b) == 2 && a->distToByCol(b) == 1) || (a->distToByRow(b) == 1 && a->distToByCol(b) == 2);
}
