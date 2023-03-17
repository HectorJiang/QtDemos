#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onStateChanged(QMediaPlayer::State state)
{

}

void MainWindow::onDurationChanged(qint64 duration)
{

}

void MainWindow::onPositionChanged(qint64 position)
{

}


void MainWindow::on_pushButton_clicked()
{
    QString strCurrentPath = QDir::homePath();//获取系统当前目录
    QString strDlgTitle = "请选择视频文件";
    QString strFilter = "mp4 Files(*.mp4);;All Files(*.*)";//文件过滤器
    QString strAllFiles = QFileDialog::getOpenFileName(this, strDlgTitle, strCurrentPath, strFilter);
    if(strAllFiles.isEmpty()){
        QMessageBox::critical(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("打开视频文件失败，请重新检查"),QMessageBox::Yes);
        return;
    }
}
