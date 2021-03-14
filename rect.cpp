#include "rect.h"

rect::rect()
{

}
void rect ::draw(QPainter *painter){
    painter->setPen(getPen());
    painter->drawRect(getStart().x(), getStart().y(), getEnd().x() - getStart().x(), getEnd().y() - getStart().y());
}
