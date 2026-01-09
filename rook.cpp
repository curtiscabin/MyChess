#include "rook.h"

Rook::Rook(QWidget*parent, QColor color) : Chess(parent, color){}

bool Rook::move_chess(Ceil *a, Ceil *b)
{

}

void Rook::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    int side = qMin(width(), height());
    painter.translate(width() / 2, height() / 2);

    // Масштаб 0.85, как у пешки, чтобы головы были на одном уровне
    double scaleFactor = (side / 100.0) * 0.85;
    painter.scale(scaleFactor, scaleFactor);

    // Стиль: жирная обводка 6px, скругленные края для "мягкости" стиля
    QPen pen(Qt::black, 6);
    pen.setJoinStyle(Qt::RoundJoin);
    pen.setCapStyle(Qt::RoundCap);
    painter.setPen(pen);
    painter.setBrush(color);

    // 1. БАШНЯ (Верхушка)
    // Рисуем прямоугольник короны с прорезями
    QPainterPath tower;
    tower.moveTo(-20, -42); // Левый верхний угол
    tower.lineTo(-20, -25); // Вниз к шее
    tower.lineTo(20, -25);  // Вправо
    tower.lineTo(20, -42);  // Вверх в правый угол

    // Зубцы
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

    // 2. ВОРОТНИК (Прямоугольник под башней)
    // Сделаем его чуть шире, чем у пешки (44 против 36)
    painter.drawRect(-22, -25, 44, 8);

    // 3. ТЕЛО (Широкое, вогнутое как у пешки)
    QPainterPath body;
    body.moveTo(-16, -17);
    // Изгиб внутрь: control point (-12, 15), конечная точка (-24, 35)
    body.quadTo(-12, 15, -24, 35);
    body.lineTo(24, 35);
    body.quadTo(12, 15, 16, -17);
    body.closeSubpath();
    painter.drawPath(body);

    // 4. БАЗА (Основание)
    // Полностью идентична пешке для единообразия ряда
    painter.drawRect(-30, 35, 60, 10);
}
