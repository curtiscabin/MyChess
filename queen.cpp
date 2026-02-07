#include "queen.h"

Queen::Queen(QWidget*parent, QColor color) : Chess(parent, color){}

void Queen::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QPen pen(Qt::black, 2);
    pen.setJoinStyle(Qt::MiterJoin);
    pen.setCapStyle(Qt::RoundCap);
    painter.setPen(pen);
    painter.setBrush(this->color);

    // 1. ГОЛОВА
    painter.drawEllipse(QPointF(25, 15), 5, 6);

    // 2. ПРОСТАЯ КОРОНА (шарик на кружке)
    // Основание
    painter.drawEllipse(QPointF(25, 10), 6, 2);
    // Шарик
    painter.drawEllipse(QPointF(25, 8), 2, 2);

    // 3. ВОРОТНИК
    painter.drawRect(21, 21, 8, 3);

    // 4. ТЕЛО
    QPainterPath body;
    body.moveTo(21, 24);
    body.quadTo(19, 31, 17, 40);
    body.lineTo(33, 40);
    body.quadTo(31, 31, 29, 24);
    body.closeSubpath();
    painter.drawPath(body);

    // 5. ПОДСТАВКА
    painter.drawRect(16, 40, 18, 3);
    painter.drawRect(12, 43, 26, 3);
}

bool Queen::pathway_rule(Ceil *a, Ceil *b)
{
    return (a->distToByRow(b) == a->distToByCol(b)) || (a->distToByCol(b) * a->distToByRow(b) == 0);
}
