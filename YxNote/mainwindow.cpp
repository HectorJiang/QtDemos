#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QColorDialog>
#include <QGraphicsOpacityEffect>

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
    QGraphicsOpacityEffect *pOpacityEffect = new QGraphicsOpacityEffect(this);
    pOpacityEffect->setOpacity(res);
    setGraphicsEffect(pOpacityEffect);
//    setWindowOpacity(res);
}

void MainWindow::on_pushButton_clicked()
{
   QColor color = QColorDialog::getColor(Qt::black, this);
   QPalette pal;
   pal.setColor(QPalette::Background, color);
   setPalette(pal);
   ui->m_pLbColor->setPalette(pal);
   ui->m_pLbColor->setAutoFillBackground(true);
}
