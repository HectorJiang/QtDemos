#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QtNetwork>
#include <QDesktopServices>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_pNetWorkManager = new QNetworkAccessManager(this);
//    connect(m_pNetWorkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetWorkReply*)));
    ui->m_pProDown->setValue(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startRequest(QUrl url)
{
   m_pNetworkReply = m_pNetWorkManager->get(QNetworkRequest(url));
   QString fileSize;
   if (m_pNetworkReply->hasRawHeader(QString("Content-Length").toUtf8()))
   {
        fileSize=m_pNetworkReply->rawHeader(QString("Content-Length").toUtf8());
        qDebug()<<fileSize<<endl;
   }
   ui->m_pLbFileSize->setText(fileSize);
   connect(m_pNetworkReply, SIGNAL(readyRead()), this, SLOT(httpReadyRead()));
   connect(m_pNetworkReply, SIGNAL(downloadProgress(qint64, qint64)), this, SLOT(updateDataReadProgress(qint64, qint64)));
   connect(m_pNetworkReply, SIGNAL(finished()), this, SLOT(httpFinished()));
}

void MainWindow::on_m_pBtnDown_clicked()
{
    m_url = ui->m_pLeURL->text();
    QFileInfo info(m_url.path());
    QString strFilename = ui->m_pLePath->text()+"/"+info.fileName();
    m_pFile = new QFile(strFilename);
    m_urlOpen = QString("file:///"+strFilename);
    if(!m_pFile->open(QIODevice::WriteOnly)){
        qDebug()<<"file open error";
        delete m_pFile;
        m_pFile = nullptr;
        return;
    }
    startRequest(m_url);
    ui->m_pProDown->setValue(0);
}

void MainWindow::on_m_pBtnBrowse_clicked()
{
    QString strPath = QFileDialog::getExistingDirectory(this, QString("choose path"));
    ui->m_pLePath->setText(strPath);
}

void MainWindow::on_m_pBtnPause_clicked()
{


}

void MainWindow::replyFinished(QNetworkReply *)
{

}

void MainWindow::httpFinished()
{
    if(ui->m_pCheckBoxIsOpen->isChecked()){
        QDesktopServices::openUrl(m_urlOpen);
    }
}

void MainWindow::httpReadyRead()
{
    if(m_pFile) m_pFile->write(m_pNetworkReply->readAll());
}

void MainWindow::updateDataReadProgress(qint64 bytesRead, qint64 totalBytes)
{
    double speed = (double)(totalBytes-bytesRead)/1024/1024;
    qDebug()<<"speed:"<<QString::number(speed, 'f', 2)<<"M/S"<<endl;
    ui->m_pProDown->setMaximum(totalBytes);
    ui->m_pProDown->setValue(bytesRead);
}
