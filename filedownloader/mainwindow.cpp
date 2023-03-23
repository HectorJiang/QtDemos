#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QtNetwork>
#include <QDesktopServices>
#include <QStatusBar>
#include <QSqlTableModel>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_pNetWorkManager = new QNetworkAccessManager(this);
    m_pSetting = new QSettings("config.ini", QSettings::IniFormat);
    m_pConsoleLogger = spdlog::stdout_color_mt("console_logger");
    m_pFileLogger = spdlog::basic_logger_mt("file_logger", "spd.log");
    m_pConsoleLogger->info("test....");
//    m_pFileLogger->warn("fafdasfda");
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("info.db");
    if(!m_db.open()){
        statusBar()->showMessage("open db error");
        m_pFileLogger->error("open db error");
    }
    m_pModelSql = new QSqlTableModel(this, m_db);
    m_pModelSql->setTable("download_record");
    ui->tableView->setModel(m_pModelSql);
    m_pModelSql->select();
    connect(ui->m_pCheckBoxIsOpen, SIGNAL(stateChanged(int)), this, SLOT(checkStateIniSet(int)));
//    connect(m_pNetWorkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetWorkReply*)));
    ui->m_pProDown->setValue(0);
    initConfig();
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

void MainWindow::initConfig()
{
    bool compleleOpen = m_pSetting->value("Basic/complete_open").toBool();
    ui->m_pCheckBoxIsOpen->setChecked(compleleOpen);
    int threadNum = m_pSetting->value("Basic/thread_num").toInt();
    ui->m_pSpinBoxThreadNum->setValue(threadNum);
}

void MainWindow::on_m_pBtnDown_clicked()
{
    m_url = ui->m_pLeURL->text();
    QFileInfo info(m_url.path());
//    if(ui->m_pLePath->text().isEmpty())
    QString strFilename = ui->m_pLePath->text()+"/"+info.fileName();
    m_pFile = new QFile(strFilename);
    m_urlOpen = QString("file:///"+strFilename);
    if(!m_pFile->open(QIODevice::WriteOnly)){
        qDebug()<<"file open error";
        statusBar()->showMessage("file open error");
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
    statusBar()->showMessage(QStringLiteral("下载成功！！！"));
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

void MainWindow::checkStateIniSet(int state)
{
    bool compleleOpen = ui->m_pCheckBoxIsOpen->isChecked();
    m_pSetting->setValue("Basic/complete_open", compleleOpen);
}

void MainWindow::on_m_pBtnClearRecord_clicked()
{
    QItemSelectionModel *pSelectModel = ui->tableView->selectionModel();
    QModelIndexList list = pSelectModel->selectedRows();
    for(auto &index:list){
        m_pModelSql->removeRow(index.row());
    }
    m_pModelSql->select();
}
