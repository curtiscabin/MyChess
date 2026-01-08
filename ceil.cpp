#include "ceil.h"

Ceil::Ceil(const QColor &color, const QPoint&p, QWidget *parent) : QPushButton(parent)
{
    this->setStyleSheet(QString("background-color: %1;").arg(color.name()));
    this->setFixedSize(50,50);
    this->move(p);
    this->show();
}

bool Ceil::isOccupied()
{
    return isOccupied_;
}

void Ceil::SetOccupied()
{
    isOccupied_ = true;
}

void Ceil::ClearOccupied()
{
    isOccupied_ = false;
}

