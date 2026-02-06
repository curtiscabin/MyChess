#ifndef CHECKMATECHECKER_H
#define CHECKMATECHECKER_H

class Ceil;
class QWidget;

class CheckMateChecker
{
public:
    CheckMateChecker();

    bool CheckChecker(Ceil*king_ceil, Ceil *from, QWidget* board1);

    bool MatChecker(Ceil *from, QWidget* board1);
};

#endif // CHECKMATECHECKER_H
