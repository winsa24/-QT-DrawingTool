#ifndef RECT_H
#define RECT_H

#include <QPainter>
#include <QPen>
#include <abstractshape.h>

class rect: public AbstractShape
{
public:
    rect();
    void draw(QPainter *painter);

};



#endif // RECT_H
