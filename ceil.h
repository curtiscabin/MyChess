#ifndef CEIL_H
#define CEIL_H

#include <QPushButton>
#include <QColor>

class Ceil : public QPushButton
{
    Q_OBJECT
public:
    Ceil(const QColor &color,const QPoint& p, QWidget*parent);
};

#endif // CEIL_H
