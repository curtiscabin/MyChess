#ifndef CEIL_H
#define CEIL_H

#include <QPushButton>
#include <QColor>
#include<QPainter>

class Ceil : public QPushButton
{
    Q_OBJECT

    bool isOccupied_ = false;
public:
    Ceil(const QColor &color,const QPoint& p,QWidget*parent);

    bool isOccupied();

    void SetOccupied();

    void ClearOccupied();
};

#endif // CEIL_H
