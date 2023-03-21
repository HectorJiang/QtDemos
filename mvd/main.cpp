#include "mainwindow.h"

#include <QApplication>
#include <QFileSystemModel>
#include <QTreeView>
#include <QListView>
#include <QStandardItemModel>
#include <QListWidget>
#include <QTreeWidget>
#include <QTableWidget>
#include <QLineEdit>
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
//    QStandardItemModel model;
//    QStandardItem *parentItem = model.invisibleRootItem();
//    QStandardItem *item0 = new QStandardItem;
//    item0->setText("A");
//    QPixmap pixmap0(50, 50);
//    pixmap0.fill("red");
//    item0->setIcon(QIcon(pixmap0));
//    item0->setToolTip(("indexA"));
//    parentItem->appendRow(item0);
//    parentItem = item0;
//    QStandardItem *item1 = new QStandardItem;
//    item1->setText("B");
//    QPixmap pixmap1(50, 50);
//    pixmap1.fill("blue");
//    item1->setIcon(QIcon(pixmap1));
//    item1->setToolTip("indexB");
//    parentItem->appendRow(item1);
//    QStandardItem *item2 = new QStandardItem;
//    QPixmap pixmap2(50, 50);
//    pixmap2.fill("green");
//    item2->setData("fdafasd", Qt::DisplayRole);
//    item2->setData("C", Qt::EditRole);
//    item2->setData("indexC",Qt::ToolTipRole);
//    item2->setData(QIcon(pixmap2), Qt::DecorationRole);
//    parentItem->appendRow(item2);
//    QTreeView view;
//    view.setModel(&model);
//    view.show();
    MainWindow w;
    w.show();
//    QListWidget listWidget;
//    QListWidgetItem * listWidgetItem = new QListWidgetItem;
//    listWidgetItem->setText("b");
//    listWidgetItem->setIcon(QIcon(":/rc/img/img.png"));
//    listWidgetItem->setToolTip("this is b");
//    listWidgetItem->setCheckState(Qt::Checked);
//    listWidgetItem->setStatusTip("fada");
//    listWidgetItem->setData(Qt::EditRole, QString("fdafaddsfasdf"));
//    listWidgetItem->setData(Qt::DecorationRole, QIcon(":/rc/img/img.png"));
//    listWidget.insertItem(0, listWidgetItem);
//    listWidget.show();

    return a.exec();
}
