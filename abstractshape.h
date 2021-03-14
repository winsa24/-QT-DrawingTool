#ifndef ABSTRACTSHAPE_H
#define ABSTRACTSHAPE_H

#include <QPainter>
#include <QPen>

class AbstractShape
{
public:
    AbstractShape();

    void setStart(QPoint a) {   startPoint = a ;};
    void setEnd(QPoint a)  {   endPoint = a ;};
    QPoint getStart() { return startPoint;};
    QPoint getEnd() { return endPoint; };
    void setPen(QPen p) { pen = p; };
    QPen getPen() { return pen; };
    void setShape(int newshape) {shape = newshape; };
    int getShape() { return shape; };

    //virtual ~AbstractShape();
    virtual void draw(QPainter *painter) = 0;

private:
//    Ui::MainWindow *ui;
    QPoint startPoint;
    QPoint endPoint;
    QPen pen;
    int shape;

};

#endif // ABSTRACTSHAPE_H
