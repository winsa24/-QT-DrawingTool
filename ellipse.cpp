#include "ellipse.h"

ellipse::ellipse()
{

}

void ellipse ::draw(QPainter *painter){
    painter->setPen(getPen());
    painter->drawEllipse(getStart().x(), getStart().y(), (getEnd().x() - getStart().x()) , (getEnd().y() - getStart().y()) );
}
