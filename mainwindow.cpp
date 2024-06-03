#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>
#include <QPainterPath>
#include <QPainter>
#include <QPen>
#include <poland.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    button = new QPushButton(this);
    button -> setGeometry(width()-5-100, 5, 100, 30);
    button -> setText("kmoqdqmke");
    connect(button, SIGNAL(clicked(bool)), this, SLOT(Clicked()));
}
const int pi = 3.1415926535;



//void MainWindow::button()
//{
//    QString s1 = ui -> lineEdit -> text();

//    double my_ans = 0.0;
//    bool p2 = calculate(s1.toStdString(), my_ans);
//    QString s3 = QString::number(my_ans);
//    //ui -> lineEdit_3->setText(s3);
//}


void MainWindow::Clicked(){


    ui->label->setGeometry(5, 5, width()-50-5-5-button->width(), height()-5-5);
    QPixmap pm(width()-5-5-5-button->width(), height()-50-5);
    pm.fill(Qt::white);


    double xMin = ui -> lineEdit_2 -> text().toDouble();
    double xMax = ui -> lineEdit_3 -> text().toDouble();

    double yMin = ui -> lineEdit_4 -> text().toDouble();
    double yMax = ui -> lineEdit_5 -> text().toDouble();

    int xgmin = 0;
    int xgmax = pm.width();

    int ygmin = 0;
    int ygmax = pm.height();

    double kx = (xgmax - xgmin) / (xMax - xMin);
    double ky = (ygmin - ygmax) / (yMax - yMin);

    double step = (xMax - xMin) / (xgmax - xgmin);


    double x = xMin, y = yMin;
    QPainterPath path;
    QPainter painter;


    path.moveTo(0, ygmin + ky * (sin(xMin) - yMax) );
    painter.begin(&pm);

    QPen pen;
    pen.setColor(Qt::red);
    painter.setPen(pen);


    double x0 = xgmin - kx * xMin;
    double y0 = ygmin - ky * yMax;

    painter.drawLine(0, y0, pm.width(), y0);
    painter.drawLine(x0, 0, x0, pm.height());

    pen.setColor(Qt::green);
    painter.setPen(pen);
    QString s1 = ui -> lineEdit -> text();
    QString s2 = ui -> lineEdit -> text();
    for(int i = xgmin; i < xgmax; i++){
        s1.replace("x", "(" + QString::number(x) + ")");
        double my_ans = 0.0;
        bool p2 = calculate(s1.toStdString(), my_ans);
        y = my_ans;
        int xg = xgmin + kx * (x - xMin);
        int yg = ygmin + ky * (y - yMax);
        path.lineTo(xg, yg);
        x += step;
        s1 = s2;
    }
    painter.drawPath(path);
    //ui -> label -> set(pm);

    ui->label->setPixmap(pm);

}



MainWindow::~MainWindow()
{
    delete ui;
}






/*
    for(int i = xgmin; i < xgmax; i++){
        s1.replace("x", "(" + QString::number(x) + ")");
        double my_ans = 0.0;
        bool p2 = calculate(s1.toStdString(), my_ans);
        if(p2 != 0){
            y = my_ans;
            int xg = xgmin + kx * (x - xMin);
            int yg = ygmin + ky * (y - yMax);
            path.lineTo(xg, yg);
            x += step;
            s1 = s2;
        }else{
            int xg = xgmin + kx * (x - xMin);
            int yg = ygmin + ky * (y - yMax);
            path.moveTo(xg, yg);
        }
    }
*/
