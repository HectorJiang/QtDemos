#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsTextItem>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_pLbPos = new QLabel(this);
    m_pLbImg = new QLabel(this);
    QPixmap p(":/img.png");
    m_pLbImg->setPixmap(p);
    m_pLbImg->move(this->width()-50, 0);
    m_pLbImg->setFixedSize(50, 50);
    statusBar()->addPermanentWidget(m_pLbPos);
    setMouseTracking(true);
    QGraphicsScene *pScene = new QGraphicsScene(this);
    QGraphicsTextItem *item1 = new QGraphicsTextItem("test");
//    QGraphicsPixmapItem *item2 = new QGraphicsPixmapItem(QPixmap(":/img.png"));
    item1->setFlags(QGraphicsItem::ItemIsSelectable|QGraphicsItem::ItemIsMovable);
//    item2->setFlag(QGraphicsItem::ItemIsSelectable);
    pScene->addItem(item1);
//    pScene->addItem(item2);
    ui->m_pGraphicView->setScene(pScene);
    setCentralWidget(ui->m_pGraphicView);
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
//    qDebug()<<"geometry"<<this->geometry().right();
//    m_pLbImg->move(this->width()-50, 0);
//    m_pLbImg->setGeometry(this->geometry().right()-50,0, 100, 100);
    m_pLbPos->setText(QString::number(e->x())+","+QString::number(e->y()));
//    qDebug()<<"mapToGlobal"<<mapToGlobal(e->pos());
//    qDebug()<<"globalPos"<<e->globalPos();
    //    qDebug()<<"mapFromGlobal"<<mapFromGlobal(e->globalPos());
}

void MainWindow::moveEvent(QMoveEvent *e)
{
    m_pLbImg->move(this->width()-50, 0);
}

void MainWindow::resizeEvent(QResizeEvent *e)
{
   m_pLbImg->move(this->width()-50, 0);
}
//void Main
