#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <QPainter>
#include <QPen>
#include <abstractshape.h>

class ellipse : public AbstractShape
{
public:
    ellipse();
    void draw(QPainter *painter);

};

#endif // ELLIPSE_H
