﻿#include "mainwindow.h"

#include <QApplication>
#include <QAbstractItemModel>
#include <QAbstractItemView>
#include <QItemSelectionModel>
#include <QDirModel>
#include <QTreeView>
#include <QListView>
#include <QTableView>
#include <QSplitter>
#include <QModelIndex>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QDirModel model;
    QTreeView tree;
    QListView list;
    QTableView table;
    tree.setModel(&model);
    list.setModel(&model);
    table.setModel(&model);
    tree.setSelectionMode(QAbstractItemView::NoSelection);
//    tree.setSelectionMode(QAbstractItemView::MultiSelection);
    list.setSelectionModel(tree.selectionModel());
//    table.setSelectionModel(tree.selectionModel());
    QObject::connect(&tree, SIGNAL(doubleClicked(QModelIndex)), &list, SLOT(setRootIndex(QModelIndex)));
    QObject::connect(&tree, SIGNAL(doubleClicked(QModelIndex)), &table, SLOT(setRootIndex(QModelIndex)));
    QSplitter *splitter = new QSplitter;
    splitter->addWidget(&tree);
    splitter->addWidget(&list);
    splitter->addWidget(&table);
    splitter->show();
//    MainWindow w;
//    w.show();
    return a.exec();
}
