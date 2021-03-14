#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    QMenuBar * menubar = this->menuBar( ); // adds/returns the menu bar
    QMenu * menu = menubar->addMenu(tr("&Colors")); // adds a pulldown menu
    QMenu * menu1 = menubar->addMenu(tr("&Styles")); // adds a pulldown menu
    QMenu * menu2 = menubar->addMenu(tr("&Thickness")); // adds a pulldown menu
    QMenu * menu3 = menubar->addMenu(tr("&Shape")); // adds a pulldown menu
    QMenu * menu4 = menubar->addMenu(tr("&Mode")); // adds a pulldown menu
//    QAction * action = new QAction( QIcon(":images/open.png"), tr("&Open..."), this );
//    QAction * action1 = new QAction( QIcon(":images/save.png"), tr("&Save..."), this );
//    QAction * action2 = new QAction( QIcon(":images/quit.png"), tr("&QQuit..."), this );

    // Add QAction
    QActionGroup *group = new QActionGroup(this);
    redAction = group->addAction(tr("red"));
    greenAction = group->addAction(tr("green"));
    blueAction = group->addAction(tr("blue"));
    // adds the action to the menu
    menu->addAction(redAction);
    menu->addAction(greenAction);
    menu->addAction(blueAction);
    // Connection
    connect(group, SIGNAL(triggered(QAction*)), this, SLOT(changeColor(QAction*)));


    QActionGroup *group1 = new QActionGroup(this);
    solidAction = group1->addAction(tr("SolidLine"));
    dashAction = group1->addAction(tr("DashLine"));
    dotAction = group1->addAction(tr("DotLine"));
    menu1->addAction(solidAction);
    menu1->addAction(dashAction);
    menu1->addAction(dotAction);
    // Connection
    connect(group1, SIGNAL(triggered(QAction*)), this, SLOT(changeStyle(QAction*)));

    QActionGroup *group2 = new QActionGroup(this);
    thinAction = group2->addAction(tr("Thin"));
    normalAction = group2->addAction(tr("Normal"));
    thickAction = group2->addAction(tr("Thick"));
    menu2->addAction(thinAction); // adds the action to the menu
    menu2->addAction(normalAction);
    menu2->addAction(thickAction);
    // Connection
    connect(group2, SIGNAL(triggered(QAction*)), this, SLOT(changeThickness(QAction*)));

    QActionGroup *group3 = new QActionGroup(this);
    lineAction = group3->addAction(tr("Line"));
    rectAction = group3->addAction(tr("Rectangle"));
    ellipseAction = group3->addAction(tr("Ellipse"));
    menu3->addAction(lineAction); // adds the action to the menu
    menu3->addAction(rectAction);
    menu3->addAction(ellipseAction);
    // Connection
    connect(group3, SIGNAL(triggered(QAction*)), this, SLOT(changeShape(QAction*)));

    QActionGroup *group4 = new QActionGroup(this);
    drawAction = group4->addAction(tr("Draw"));
    selAction = group4->addAction(tr("Select"));
    moveAction = group4->addAction(tr("Move"));
    scaleAction = group4->addAction(tr("Scale"));
    caAction = group4->addAction(tr("Change Attributes"));
    menu4->addAction(drawAction); // adds the action to the menu
    menu4->addAction(selAction);
    menu4->addAction(moveAction);
    menu4->addAction(scaleAction);
    menu4->addAction(caAction);
    // Connection
    connect(group4, SIGNAL(triggered(QAction*)), this, SLOT(changeMode(QAction*)));

//    QMenu * setmenu = menubar->addMenu(tr("&File")); // adds a pulldown menu
    // new.png is specified in a resource file (see later)
    QAction * action = new QAction( QIcon(":images/open.png"), tr("&Open..."), this );
    QAction * action1 = new QAction( QIcon(":images/save.png"), tr("&Save..."), this );
    QAction * action2 = new QAction( QIcon(":images/quit.png"), tr("&QQuit..."), this );
    QToolBar * toolbar = this->addToolBar( tr("File") );
    toolbar->addAction(action);
    toolbar->addAction(action1);
    toolbar->addAction(action2);
    connect(action, SIGNAL(triggered( )), this, SLOT(openFile( ))); // connection
    connect(action1, SIGNAL(triggered( )), this, SLOT(saveFile( ))); // connection
    connect(action2, SIGNAL(triggered( )), this, SLOT(quitApp( ))); // connection


//    menu2->addAction(action); // adds the action to the menu
//    menu2->addAction(action1);
//    menu2->addAction(action2);

    myCanvas = new canvas(this);
//    this->setCentralWidget(ui->MainLayout_2);
    ui->setupUi(this);
    ui->MainLayout->addWidget(myCanvas);

    //color
    btn_g1 = new QButtonGroup(this);
    btn_g1->addButton(ui->red, 0);
    btn_g1->addButton(ui->green, 1);
    btn_g1->addButton(ui->blue, 2);
    //ui->red->setChecked(true);
    //style
    btn_g2 = new QButtonGroup(this);
    btn_g2->addButton(ui->solid, 0);
    btn_g2->addButton(ui->dash, 1);
    btn_g2->addButton(ui->dot, 2);
    ui->solid->setChecked(true);
    //thickness
    btn_g3 = new QButtonGroup(this);
    btn_g3->addButton(ui->thin, 0);
    btn_g3->addButton(ui->normal, 1);
    btn_g3->addButton(ui->thick, 2);
    ui->normal->setChecked(true);
    //shape
    btn_g4 = new QButtonGroup(this);
    btn_g4->addButton(ui->line, 0);
    btn_g4->addButton(ui->rectangle, 1);
    btn_g4->addButton(ui->ellipse, 2);
    ui->line->setChecked(true);
    //mode
    btn_g5 = new QButtonGroup(this);
    btn_g5->addButton(ui->draw, 0);
    btn_g5->addButton(ui->select, 1);
    btn_g5->addButton(ui->move, 2);
    btn_g5->addButton(ui->scale, 3);
    btn_g5->addButton(ui->ChangeAttributes, 4);
    ui->draw->setChecked(true);

    connect(ui->red, SIGNAL(clicked()), this, SLOT(slots_color()));
    connect(ui->green, SIGNAL(clicked()), this, SLOT(slots_color()));
    connect(ui->blue, SIGNAL(clicked()), this, SLOT(slots_color()));

    connect(ui->solid, SIGNAL(clicked()), this, SLOT(slots_style()));
    connect(ui->dash, SIGNAL(clicked()), this, SLOT(slots_style()));
    connect(ui->dot, SIGNAL(clicked()), this, SLOT(slots_style()));

    connect(ui->thin, SIGNAL(clicked()), this, SLOT(slots_thickness()));
    connect(ui->normal, SIGNAL(clicked()), this, SLOT(slots_thickness()));
    connect(ui->thick, SIGNAL(clicked()), this, SLOT(slots_thickness()));

    connect(ui->line, SIGNAL(clicked()), this, SLOT(slots_shape()));
    connect(ui->rectangle, SIGNAL(clicked()), this, SLOT(slots_shape()));
    connect(ui->ellipse, SIGNAL(clicked()), this, SLOT(slots_shape()));

    connect(ui->draw, SIGNAL(clicked()), this, SLOT(slots_mode()));
    connect(ui->select, SIGNAL(clicked()), this, SLOT(slots_mode()));
    connect(ui->move, SIGNAL(clicked()), this, SLOT(slots_mode()));
    connect(ui->scale, SIGNAL(clicked()), this, SLOT(slots_mode()));
    connect(ui->ChangeAttributes, SIGNAL(clicked()), this, SLOT(slots_mode()));

    connect(ui->slider, SIGNAL(valueChanged(int)), this, SLOT(setSlidervalue()));
    connect(ui->slider2, SIGNAL(valueChanged(int)), this, SLOT(setSlidervalue2()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

// Respond function
void MainWindow::changeColor(QAction *action)
{
    if (action == redAction) {
        // TO DO
        qDebug() << "red";
        myCanvas->setColor(Qt::red);
    }
    if (action == greenAction) {
        // TO DO
        qDebug() << "green";
        myCanvas->setColor(Qt::green);
    }
    if (action == blueAction) {
        // TO DO
        qDebug() << "blue";
        myCanvas->setColor(Qt::blue);
    }
}

void MainWindow::changeStyle(QAction *action)
{
    if (action == solidAction) {
        myCanvas->setStyle(Qt::SolidLine);
    }
    if (action == dashAction) {
        myCanvas->setStyle(Qt::DashLine);
    }
    if (action == dotAction) {
        myCanvas->setStyle(Qt::DotLine);
    }
}

void MainWindow::changeThickness(QAction *action)
{
    if (action == thinAction) {
        myCanvas->setThickness(1);
    }
    if (action == normalAction) {
        myCanvas->setThickness(3);
    }
    if (action == thickAction) {
       myCanvas->setThickness(5);
    }
}

void MainWindow::changeShape(QAction *action)
{
    if (action == lineAction) {
        myCanvas->setShape(0);
    }
    if (action == rectAction) {
        myCanvas->setShape(1);
    }
    if (action == ellipseAction) {
       myCanvas->setShape(2);
    }
}

void MainWindow::changeMode(QAction *action)
{
    if (action == drawAction) {
        // TO DO
        myCanvas->mode = 0;
    }
    if (action == selAction) {
        // TO DO
        myCanvas->mode = 1;
    }
    if (action == moveAction) {
        // TO DO
        myCanvas->mode = 2;
    }
    if (action == scaleAction) {
        // TO DO
        myCanvas->mode = 3;
    }
    if (action == caAction) {
        // TO DO
        myCanvas->mode = 4;
        //qDebug() << "edit";
    }

}

// link to ui

void MainWindow::slots_color()
{
    myCanvas->update();
    switch(btn_g1->checkedId())
       {
       case 0:
           myCanvas->setColor(Qt::red);
           break;
       case 1:
           myCanvas->setColor(Qt::green);
           break;
       case 2:
           myCanvas->setColor(Qt::blue);
           break;
       }

}
void MainWindow::slots_style()
{
    myCanvas->update();
    switch(btn_g2->checkedId())
       {
       case 0:
           myCanvas->setStyle(Qt::SolidLine);
           break;
       case 1:
           myCanvas->setStyle(Qt::DashLine);
           break;
       case 2:
           myCanvas->setStyle(Qt::DotLine);
           break;
       }

}
void MainWindow::slots_thickness()
{
    myCanvas->update();
    switch(btn_g3->checkedId())
       {
       case 0:
           myCanvas->setThickness(1);
           break;
       case 1:
           myCanvas->setThickness(5);
           break;
       case 2:
           myCanvas->setThickness(10);
           break;
       }

}
void MainWindow::slots_shape()
{
    switch(btn_g4->checkedId())
       {
       case 0:
           myCanvas->setShape(0);
           break;
       case 1:
           myCanvas->setShape(1);
           break;
       case 2:
           myCanvas->setShape(2);
           break;
       }
}
void MainWindow::slots_mode()
{
    switch(btn_g5->checkedId())
       {
       case 0:
           myCanvas->mode = 0;
           break;
       case 1:
           myCanvas->mode = 1;
           break;
       case 2:
           myCanvas->mode = 2;
           break;
       case 3:
            myCanvas->mode = 3;
            myCanvas->scale_flag = true;
            break;
       case 4:
            myCanvas->mode = 4;
            break;
       }
}
void MainWindow::setSlidervalue(){
    int v1 = ui->slider->value();
    myCanvas->setThickness(v1);
    qDebug() << v1;
    myCanvas->update();
}
void MainWindow::setSlidervalue2(){
    int v1 = ui->slider2->value();
    myCanvas->scale = v1;
    qDebug() << v1;
    myCanvas->update();
}

void MainWindow::closeEvent (QCloseEvent *event)
{
    QMessageBox::StandardButton resBtn = QMessageBox::question( this, "APP_NAME",
                                                                tr("Are you sure?\n"),
                                                                QMessageBox::No | QMessageBox::Yes,
                                                                QMessageBox::Yes);
    if (resBtn != QMessageBox::Yes) {
        event->ignore();
    } else {
        event->accept();
    }
}

void MainWindow::openFile(){
    QString filename =
            QFileDialog::getOpenFileName(this,tr("Open Image"),
//                                         "/Users/weixiang/QtWorkSpace",
                                          "/",
                                         tr("Images (*.png *.bmp *.jpg)"));
        if(filename.isEmpty())
            return;
        else
        {
            QImage img;
            if(!(img.load(filename)))
            {
                QMessageBox::information(this, tr("failed"),tr("failed"));
                return;
            }
            myCanvas->openimage(img);
            myCanvas->update();

//            ui->label->setPixmap(QPixmap::fromImage(img.scaled(ui->label->size())));
        }
}
void MainWindow ::saveFile(){
    QString file_path =
            QFileDialog::getSaveFileName(this, tr("Save Image"), // title
//            "/Users/weixiang/QtWorkSpace", // directory
                                         "/",
            tr("Images (*.jpg *.bmp *.png)") // filter
            );

    if(!file_path.isEmpty())
    {

        if(QFileInfo(file_path).suffix().isEmpty())
            file_path.append(".png");
        myCanvas->saveimage();
        myCanvas->m_image.save(file_path);
    }


}

void MainWindow ::quitApp(){

    QMessageBox::StandardButton resBtn = QMessageBox::question( this, "APP_NAME",
                                                                tr("Are you sure?\n"),
                                                                QMessageBox::No | QMessageBox::Yes,
                                                                QMessageBox::Yes);
    if (resBtn == QMessageBox::Yes) {
        QApplication::quit();
    }

}
