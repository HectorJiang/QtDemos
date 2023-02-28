#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "customscene.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    CustomScene *pCustomScene = new CustomScene();
    ui->graphicsView->setScene(pCustomScene);
//    ui->graphicsView->setSceneRect(ui->graphicsView->rect());
    ui->listWidget->setDragEnabled(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

