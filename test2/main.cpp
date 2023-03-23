#include "mainwindow.h"
#include "modelex.h"
#include <QApplication>
#include <QTableView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
    ModelEx modelEx;
    QTableView view;
    view.setModel(&modelEx);
    view.show();
    return a.exec();
}
