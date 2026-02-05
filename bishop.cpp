#include "bishop.h"

Bishop::Bishop(QWidget*parent, QColor color) : Chess(parent, color){}

bool Bishop::move_chess(Ceil *a, Ceil *b)
{
    qDebug()<<"enter to go to move_chess";
    if(!(abs(b->getRow() - a->getRow()) == abs(b->getCol() - a->getCol())) || a == b)return false;
    qDebug()<<"after first check of bishop";
    WayChecker wayCheck;
    //horizontal
    if(!wayCheck.onBoardIsWayFromToClear(a,b,a->parentWidget()))
        return false;
    qDebug()<<"after wayCheck of bishop";
    if(b->getChess()){
        cut_chess(b);
    }
    else{
        setParent(b);
    }

    raise();
    show();
    qDebug()<<"over move_chess";
    return true;
}

void Bishop::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // --- НАСТРОЙКИ СТИЛЯ ---
    QPen pen(Qt::black, 2);
    pen.setJoinStyle(Qt::MiterJoin);
    pen.setCapStyle(Qt::RoundCap);
    painter.setPen(pen);
    painter.setBrush(this->color);

    // 1. НАВЕРШИЕ (Шарик)
    // Поднимаем почти к самому верху ячейки
    painter.drawEllipse(QPointF(25, 4), 2.5, 2.5);

    // 2. ГОЛОВА С ВЫРЕЗОМ (МИТРА)
    QPainterPath headPath;
    // Овал головы: теперь начинается от y=7
    QRectF headRect(19, 7, 12, 17);
    headPath.addEllipse(headRect);

    // Разрез (вычитаем сектор)
    QPainterPath cut;
    cut.moveTo(25, 12);
    cut.lineTo(33, 8);
    cut.lineTo(33, 16);
    cut.closeSubpath();

    QPainterPath finalHead = headPath.subtracted(cut);
    painter.drawPath(finalHead);

    // 3. ВОРОТНИК
    // Опускаем чуть ниже головы (y=24)
    painter.drawRect(21, 24, 8, 3);

    // 4. ТУЛОВИЩЕ (Удлиненное)
    QPainterPath body;
    body.moveTo(21, 27);
    // Растягиваем путь вниз до y=40 (раньше туловище заканчивалось выше)
    body.quadTo(19, 34, 17, 40);
    body.lineTo(33, 40);
    body.quadTo(31, 34, 29, 27);
    body.closeSubpath();
    painter.drawPath(body);

    // 5. ПОДСТАВКА (Теперь на одном уровне с другими фигурами)
    // Рисуем две ступеньки основания, как у коня, чтобы по высоте дойти до y=45
    painter.drawRect(16, 40, 18, 3); // Верхняя часть подставки
    painter.drawRect(12, 43, 26, 3); // Нижняя часть подставки (до y=46)
}
