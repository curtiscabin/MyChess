#include "bishop.h"

Bishop::Bishop(QWidget*parent, QColor color) : Chess(parent, color){}

void Bishop::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QPen pen(Qt::black, 2);
    pen.setJoinStyle(Qt::MiterJoin);
    pen.setCapStyle(Qt::RoundCap);
    painter.setPen(pen);
    painter.setBrush(this->color);

    painter.drawEllipse(QPointF(25, 4), 2.5, 2.5);

    QPainterPath headPath;
    QRectF headRect(19, 7, 12, 17);
    headPath.addEllipse(headRect);

    QPainterPath cut;
    cut.moveTo(25, 12);
    cut.lineTo(33, 8);
    cut.lineTo(33, 16);
    cut.closeSubpath();

    QPainterPath finalHead = headPath.subtracted(cut);
    painter.drawPath(finalHead);

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

bool Bishop::pathway_rule(Ceil *a, Ceil *b)
{
    return a->distToByRow(b) == a->distToByCol(b);
}
