#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QUrl>
//#include <QNetworkReply>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class QNetworkReply;
class QNetworkAccessManager;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void startRequest(QUrl url);

private slots:
    void on_m_pBtnDown_clicked();

    void on_m_pBtnBrowse_clicked();

    void on_m_pBtnPause_clicked();

    void replyFinished(QNetworkReply *);
    void httpFinished();
    void httpReadyRead();
    void updateDataReadProgress(qint64, qint64);

private:
    QNetworkAccessManager *m_pNetWorkManager;
    QNetworkReply *m_pNetworkReply;
    QUrl m_url;
    QFile *m_pFile;
    QUrl m_urlOpen;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
