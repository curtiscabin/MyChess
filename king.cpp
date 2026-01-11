#include "king.h"

King::King(QWidget*parent, QColor color) : Chess(parent, color){}

bool King::move_chess(Ceil *a, Ceil *b)
{

}

void King::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // Для креста используем более толстое перо
    QPen crossPen(Qt::black, 2.5);
    crossPen.setJoinStyle(Qt::RoundJoin);
    crossPen.setCapStyle(Qt::RoundCap);

    // Для остальных частей - обычное
    QPen normalPen(Qt::black, 2);
    normalPen.setJoinStyle(Qt::RoundJoin);
    normalPen.setCapStyle(Qt::RoundCap);

    painter.setBrush(this->color);

    // Крест с толстым пером
    painter.setPen(crossPen);
    painter.drawLine(25, 8, 25, 15);
    painter.drawLine(21, 11, 29, 11);
    painter.drawEllipse(QPointF(25, 7), 2, 2);

    // Остальные части с нормальным пером
    painter.setPen(normalPen);

    // Большая голова
    painter.drawEllipse(QPointF(25, 19), 4.5, 4.5);

    // Воротник
    painter.drawRect(21, 24, 8, 3);

    // Тело
    QPainterPath body;
    body.moveTo(21, 27);
    body.quadTo(19, 34, 17, 40);
    body.lineTo(33, 40);
    body.quadTo(31, 34, 29, 27);
    body.closeSubpath();
    painter.drawPath(body);

    // Основание
    painter.drawRect(16, 40, 18, 3);
    painter.drawRect(12, 43, 26, 3);
}
