#include "knight.h"

Knight::Knight(QWidget*parent, QColor color) : Chess(parent, color){}

bool Knight::move_chess(Ceil *a, Ceil *b)
{

}

void Knight::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // --- СТИЛЬ ИЗ ПЕШКИ ---
    QPen pen(Qt::black, 2); // Толщина 2, так как в 50x50 шестерка будет слишком жирной
    pen.setJoinStyle(Qt::MiterJoin);
    pen.setCapStyle(Qt::RoundCap);
    painter.setPen(pen);
    painter.setBrush(this->color); // Используем твое поле color

    // --- ОСНОВАНИЕ ---
    QPainterPath base;
    base.moveTo(10, 45);
    base.lineTo(40, 45);
    base.lineTo(38, 40);
    base.lineTo(12, 40);
    base.closeSubpath();
    painter.drawPath(base);

    // --- ОБОДОК (ВАЛИК) ---
    // Используем drawRoundedRect, чтобы заливка сработала как в Rect у пешки
    painter.drawRoundedRect(11, 35, 28, 5, 2, 2);

    // --- ТЕЛО КОНЯ ---
    QPainterPath body;
    // Начинаем снизу справа от ободка
    body.moveTo(35, 35);

    // Спина и затылок
    body.cubicTo(38, 25, 36, 10, 25, 8);

    // Ушко
    body.lineTo(23, 5);
    body.lineTo(20, 9);

    // Лоб и нос
    body.lineTo(12, 16);
    body.lineTo(8, 22);

    // Нижняя челюсть / рот
    body.lineTo(11, 25);
    body.lineTo(13, 23);

    // Грудь и шея
    body.quadTo(25, 25, 15, 35);

    // Замыкаем контур
    body.lineTo(35, 35);
    body.closeSubpath();

    painter.drawPath(body);
}
