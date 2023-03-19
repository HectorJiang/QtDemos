#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QColorDialog>

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

void MainWindow::on_pushButton_clicked()
{
   QColor color = QColorDialog::getColor(Qt::black, this);
   QPalette pal = palette();
   pal.setColor(QPalette::Background, color);
   setPalette(pal);
}
