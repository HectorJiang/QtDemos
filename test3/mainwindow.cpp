#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("info.db");
    if(!db.open()){
        QMessageBox::warning(this, "error", db.lastError().text(), QMessageBox::Ok);
        return;
    }
    model = new QSqlTableModel(this);
    model->setTable("student");
    ui->tableView->setModel(model);
    model->setHeaderData(0, Qt::Horizontal, "num");
    model->select();
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_m_pBtnAdd_clicked()
{
    QSqlRecord record = model->record();
    int row = model->rowCount();
    model->insertRecord(row, record);
}

void MainWindow::on_m_pBtnDel_clicked()
{
    QItemSelectionModel *pSelectModel = ui->tableView->selectionModel();
    QModelIndexList list = pSelectModel->selectedRows();
    for(auto &index:list){
        model->removeRow(index.row());
    }
}

void MainWindow::on_m_pBtnSure_clicked()
{
    model->submitAll();
}

void MainWindow::on_m_pBtnCancel_clicked()
{
    model->revertAll();
}

void MainWindow::on_m_pBtnFind_clicked()
{
    QString str = ui->lineEdit->text();
    QString name = QString("name='%1'").arg(str);
    model->setFilter(name);
    model->select();
}
