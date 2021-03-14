#ifndef PAINTER_H
#define PAINTER_H


#include <QWidget>
#include <QPainter>
#include <QPen>
#include <QMouseEvent>
#include <QMenuBar>
#include <QMenu>
#include <QToolBar>
#include <QStatusBar>
#include <QAction>
#include <line.h>
#include <rect.h>
#include <ellipse.h>
#include <QList>
#include <abstractshape.h>
#include <QPainterPath>


class canvas : public QWidget
{
    Q_OBJECT
public:
    explicit canvas(QWidget *parent = nullptr);
    void setColor(Qt::GlobalColor newcolor){ color = newcolor;};
    void setStyle(Qt::PenStyle newstyle){ style = newstyle;};
    void setThickness(int newThickness){ thickness = newThickness;};
    void setShape(int newShape){ shape = newShape;};
    int mode = 0; //0 : draw ; 1 : select; 2: move; 3: scale 4: changeAttributes
    int scale = 0;
    bool scale_flag = true;
    QPoint o_started, o_ended;
    QImage m_image, r_image;


signals:


public:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);

    void saveimage();
    void openimage(QImage);


private:
//    Ui::MainWindow *ui;
    QPen pen;
    Qt::GlobalColor color = Qt::black;
    Qt::PenStyle style = Qt::SolidLine;
    int thickness = 3;
    int shape = 0; // 0 = line ; 1 = rect ; 2 = ellipse ;

    QPoint startPoint;
    QPoint endPoint;

    QList<AbstractShape *> list {}; //coutinues drawing
    QList<AbstractShape *> finalDrawlist {};    //draw results
    AbstractShape *abs; //current painting
    //QList<QPen> penList;
    QList<QPainterPath> pathlist;   //draw results
    QPainterPath path;
    int selnum = 0; //selected shape
    QPainterPath selpath;



};

#endif // PAINTER_H
