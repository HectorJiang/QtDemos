#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStandardItemModel>
#include <QTableView>
#include "spinboxdelegate.h"
#include <QLineEdit>
#include <QLabel>
#include <QPainter>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    QStandardItemModel *model = new QStandardItemModel(7, 4, this);
//    for(int row=0; row<7; row++)
//        for(int column = 0; column<4; column++){
//            QStandardItem *item = new QStandardItem(QString("%1").arg(row*4 + column));
//            model->setItem(row, column, item);
//        }

//    QTableView *view = new QTableView(this);
//    view->setSortingEnabled(true);
//    view->setModel(model);
//    setCentralWidget(view);

//    QItemSelectionModel *selectModel = view->selectionModel();
//    QModelIndex topLeft, bottomRight;
//    topLeft = model->index(1, 1, QModelIndex());
//    bottomRight = model->index(5, 2, QModelIndex());
//    QItemSelection selection(topLeft, bottomRight);
//    selectModel->select(selection, QItemSelectionModel::Select|QItemSelectionModel::Rows);
//    view->show();
//    SpinBoxDelegate *delegate = new SpinBoxDelegate(this);
//    view->setItemDelegate(delegate);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e)
    QPainter p(this);
    p.setPen(QColor(170, 255, 127, 150));
    p.setBrush(QBrush(Qt::Dense1Pattern));
    p.drawLine(0, 0, 20, 20);
}


