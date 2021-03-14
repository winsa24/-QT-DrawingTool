#include "line.h"

line::line()
{

}

void line ::draw(QPainter *painter){
    painter->setPen(getPen());
    painter->drawLine(getStart(), getEnd());
}
