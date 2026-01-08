#include "pawn.h"

Pawn::Pawn(QWidget*parent, QColor color) : Chess(parent, color){}

bool Pawn::move_chess(Ceil *a, Ceil *b)
{



}
void Pawn::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // --- 1. Настройка масштаба с отступами ---
    int side = qMin(width(), height()); // В твоем случае это будет 50
    painter.translate(width() / 2, height() / 2);

    // БЫЛО: double scaleFactor = side / 100.0;
    // СТАЛО: Добавляем множитель 0.75 (или 0.7), чтобы уменьшить фигуру
    double scaleFactor = (side / 100.0) * 0.85;

    painter.scale(scaleFactor, scaleFactor);

    // --- 2. Стиль линий (остальное без изменений) ---
    // Важно: так как мы уменьшили масштаб (zoom out), линии визуально станут тоньше.
    // Если хочешь сохранить ту же "жирность", можно чуть увеличить толщину пера здесь.
    // Например, было 6, можно поставить 8, если покажется слишком тонко.
    QPen pen(Qt::black, 6);
    pen.setJoinStyle(Qt::MiterJoin);
    pen.setCapStyle(Qt::RoundCap);
    painter.setPen(pen);
    painter.setBrush(color);

    // ... Дальше код рисования (Голова, Воротник, Тело, База) вообще не меняй ...

    // А. ГОЛОВА
    painter.drawEllipse(QPointF(0, -28), 16, 16);

    // Б. ВОРОТНИК
    painter.drawRect(-18, -10, 36, 8);

    // В. ТЕЛО
    QPainterPath body;
    body.moveTo(-12, -2);
    body.quadTo(-8, 15, -22, 35);
    body.lineTo(22, 35);
    body.quadTo(8, 15, 12, -2);
    body.closeSubpath();
    painter.drawPath(body);

    // Г. БАЗА
    painter.drawRect(-30, 35, 60, 10);
}
