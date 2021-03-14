#include "canvas.h"
#include <QtDebug>

canvas::canvas(QWidget *parent) : QWidget(parent)
{
    this->setMinimumSize(500, 500);    

}

void canvas::paintEvent (QPaintEvent *){
    QPainter *painter = new QPainter(this);

    QPoint p(0, 0);
    painter->drawImage(p, r_image);

    if(mode == 3){  //scale
        //get a scale number (-5 ~ 5)
//            int scale = 20;

        if(scale_flag){
            o_started = finalDrawlist[selnum]->getStart();
            o_ended = finalDrawlist[selnum]->getEnd();
            scale_flag = false;
        }

        //keep original size
        QPoint started, ended;

        started.setX(o_started.x() - scale);
        started.setY(o_started.y() - scale);
        ended.setX(o_ended.x() + scale);
        ended.setY(o_ended.y() + scale);

        finalDrawlist[selnum]->setStart(started);
        finalDrawlist[selnum]->setEnd(ended);

    }

    if(mode == 4){  //change attributes
        //attributes
        pen.setColor(color);
        pen.setStyle(style);
        pen.setWidth(thickness);
        finalDrawlist[selnum]->setPen(pen);
    }

    for (int i = 0; i < list.size(); i ++ ){
        list[i]->draw(painter);
    }

    //select a shape
    pen.setColor(Qt::yellow);
    pen.setStyle(Qt::DashDotDotLine);
    pen.setWidth(1);
    painter->setPen(pen);
    painter->drawPath(selpath);



    delete painter;
}

void canvas::saveimage(){
    QImage image(QSize(this->width(),this->height()),QImage::Format_ARGB32);
    image.fill("white");
    QPainter *painter = new QPainter(&image);
    for (int i = 0; i < list.size(); i ++ ){
        list[i]->draw(painter);
    }
    delete painter;
    m_image = image;
}
void canvas::openimage(QImage img)
{
//    QPainter *painter = new QPainter(this);
//    QPoint p(0, 0);
//    painter->drawImage(p, img);
//    delete painter;
    r_image = img;
}

void canvas::mousePressEvent(QMouseEvent* event) {

    if (event->button() == Qt::LeftButton) {
        startPoint = endPoint = event->pos();

        if(mode == 0){
            switch (shape) {
                case 0:{
                    abs = new line();
                    abs->setStart(startPoint);
                    abs->setEnd(endPoint);
                    abs->setShape(0);
                break;
            }
            case 1:
                    abs = new class rect();
                    abs->setStart(startPoint);
                    abs->setEnd(endPoint);
                    abs->setShape(1);
                break;
            case 2:
                    abs = new ellipse();
                    abs->setStart(startPoint);
                    abs->setEnd(endPoint);
                    abs->setShape(2);
                break;
            }
            pen.setColor(color);
            pen.setStyle(style);
            pen.setWidth(thickness);
            abs->setPen(pen);
            list.append(abs);
            //penList.append(pen);

            path.moveTo(startPoint);
        }
        if(mode == 1){ //select
            QPainterPath mouse;
            mouse.clear();
            mouse.addRect(startPoint.x() - 2, startPoint.y() - 2, 4, 4);
            for (int i = 0; i < pathlist.size(); i ++ ){
                if(pathlist[i].intersects(mouse)){
                    selpath = pathlist[i];
//                    QPointF qf = selpath.currentPosition();
//                    qDebug() << qf;
//                    qDebug() << i;
                    selnum = i;
                    qDebug() << selnum;
                }
            }
        }

        update(); // dont forget!

    }

}

void canvas::mouseMoveEvent(QMouseEvent* event) {

        if(mode == 0){
            endPoint = event->pos();
            abs->setStart(startPoint);
            abs->setEnd(endPoint);
            list.append(abs);
        }

        update(); // dont forget!

}

void canvas::mouseReleaseEvent(QMouseEvent* event) {

    if (event->button() == Qt::LeftButton) {
        endPoint = event->pos();
        if(mode == 0){
            //endPoint = event->pos();
            abs->setStart(startPoint);
            abs->setEnd(endPoint);
            list.append(abs);
            finalDrawlist.append(abs);

            path.clear();
            switch (shape) {
                case 0:{
                    path.moveTo(startPoint);
                    path.lineTo(endPoint);
                    path.closeSubpath();
                break;
            }
            case 1:
                    path.addRect(startPoint.x(), startPoint.y(), (endPoint.x() - startPoint.x()), (endPoint.y() - startPoint.y()));
                break;
            case 2:
                    path.addEllipse(startPoint.x(), startPoint.y(), (endPoint.x() - startPoint.x()), (endPoint.y() - startPoint.y()));
                break;
            }
            pathlist.append(path);
        }
        if(mode == 2){  //move
            //calculate distance between movement
            int disX = startPoint.x() - endPoint.x();
            int disY = startPoint.y() - endPoint.y();
            QPoint started = finalDrawlist[selnum]->getStart();
            QPoint ended = finalDrawlist[selnum]->getEnd();
            //keep original size
            started.setX(started.x() - disX);
            started.setY(started.y() - disY);
            ended.setX(ended.x() - disX);
            ended.setY(ended.y() - disY);
            finalDrawlist[selnum]->setStart(started);
            finalDrawlist[selnum]->setEnd(ended);

            //maintain pathlist
            //create a new path
            QPainterPath newpath;

            int selshape = finalDrawlist[selnum]->getShape();

            switch(selshape){
                case 0:{
                    newpath.moveTo(started);
                    newpath.lineTo(ended);
                    newpath.closeSubpath();
                break;
                }
                case 1:
                    newpath.addRect(started.x(), started.y(), (ended.x() - started.x()), (ended.y() - started.y()));
                break;
                case 2:
                    newpath.addEllipse(started.x(), started.y(), (ended.x() - started.x()), (ended.y() - started.y()));
                break;
            }
            //set new path to pathlist[selnum]
            pathlist[selnum] = newpath;

        }
//        if(mode == 3){  //scale
//            //get a scale number (-5 ~ 5)
//            int scale = 20;
//            QPoint started = finalDrawlist[selnum]->getStart();
//            QPoint ended = finalDrawlist[selnum]->getEnd();
//            //keep original size
//            started.setX(started.x() - scale);
//            started.setY(started.y() - scale);
//            ended.setX(ended.x() + scale);
//            ended.setY(ended.y() + scale);
//            finalDrawlist[selnum]->setStart(started);
//            finalDrawlist[selnum]->setEnd(ended);
//        }

        update(); // dont forget!
    }

}
