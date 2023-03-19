#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_m_pSliderOpacity_valueChanged(int value)
{
    qreal res = static_cast<qreal>(value)/10;
    qDebug()<<res;
    setWindowOpacity(res);
}
