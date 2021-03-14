#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QTextEdit>
#include <QPainter>
#include <QPen>
#include <QMouseEvent>
#include <QMenuBar>
#include <QMenu>
#include <QToolBar>
#include <QStatusBar>
#include <QAction>
#include <QDebug>
#include <canvas.h>
#include <QButtonGroup>
#include <QMessageBox>
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent *event) override;

public slots:
    void changeColor(QAction *action);
    void changeStyle(QAction *action);
    void changeThickness(QAction *action);
    void changeShape(QAction *action);
    void changeMode(QAction *action);

    //ui
    void slots_color();
    void slots_style();
    void slots_thickness();
    void slots_shape();
    void slots_mode();

    //slider
    void setSlidervalue();
    void setSlidervalue2();

    //menu
    void openFile();
    void saveFile();
    void quitApp();


private:
    Ui::MainWindow *ui;
    canvas *myCanvas;
    QAction *redAction, *greenAction, *blueAction;
    QAction *solidAction, *dashAction, *dotAction;
    QAction *thinAction, *normalAction, *thickAction;
    QAction *lineAction, *rectAction, *ellipseAction;
    QAction *drawAction, *selAction, *moveAction, *scaleAction, *caAction;
    QButtonGroup *btn_g1, *btn_g2, *btn_g3, *btn_g4, *btn_g5;

};
#endif // MAINWINDOW_H
