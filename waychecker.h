#ifndef WAYCHECKER_H
#define WAYCHECKER_H

class Ceil;
class QWidget;

class WayChecker
{
public:
    WayChecker();

    bool onBoardIsWayFromToClear(Ceil* a, Ceil* b, QWidget* board1);
};

#endif // WAYCHECKER_H
