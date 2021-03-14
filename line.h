#ifndef LINE_H
#define LINE_H

#include <QPainter>
#include <QPen>
#include <abstractshape.h>

class line : public AbstractShape
{
public:
    line();
    void draw(QPainter *painter);

private:


};

#endif // LINE_H
