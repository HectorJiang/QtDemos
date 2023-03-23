#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QColorDialog>
#include <QGraphicsOpacityEffect>
#include <QGraphicsDropShadowEffect>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->m_pSliderOpacity->setValue(10);
    ui->m_pLbColor->setFixedSize(250, 80);
//    setWindowFlags(Qt::FramelessWindowHint);
    QGraphicsDropShadowEffect *pShadowEffect = new QGraphicsDropShadowEffect(this);
    pShadowEffect->setOffset(20, 20);
    pShadowEffect->setColor(QColor(150,150,150));
    pShadowEffect->setBlurRadius(6);
//    ui->m_pWdt1->setGraphicsEffect(pShadowEffect);
//    ui->m_pWdt2->setGraphicsEffect(pShadowEffect);
    ui->widget->setGraphicsEffect(pShadowEffect);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_m_pSliderOpacity_valueChanged(int value)
{
    qreal res = static_cast<qreal>(value)/10;
//    qDebug()<<res;
//    QGraphicsOpacityEffect *pOpacityEffect = new QGraphicsOpacityEffect(this);
//    pOpacityEffect->setOpacity(res);
//    setGraphicsEffect(pOpacityEffect);
    setWindowOpacity(res);
}

void MainWindow::on_pushButton_clicked()
{
   QColor color = QColorDialog::getColor(Qt::black, this);
   QPalette pal;
   pal.setColor(QPalette::Background, color);
//   setPalette(pal);
   ui->m_pLbColor->setPalette(pal);
   ui->m_pLbColor->setAutoFillBackground(true);
}
