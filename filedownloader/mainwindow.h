#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QUrl>
#include <QSettings>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <QSqlTableModel>
#include <QSqlDatabase>
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
private:
    void initConfig();
private slots:
    void on_m_pBtnDown_clicked();

    void on_m_pBtnBrowse_clicked();

    void on_m_pBtnPause_clicked();

    void replyFinished(QNetworkReply *);
    void httpFinished();
    void httpReadyRead();
    void updateDataReadProgress(qint64, qint64);
    void checkStateIniSet(int state);

    void on_m_pBtnClearRecord_clicked();

private:
    QNetworkAccessManager *m_pNetWorkManager;
    QNetworkReply *m_pNetworkReply;
    QUrl m_url;
    QFile *m_pFile;
    QUrl m_urlOpen;
    Ui::MainWindow *ui;
    QSettings *m_pSetting;
    std::shared_ptr<spdlog::logger> m_pConsoleLogger;
    std::shared_ptr<spdlog::logger> m_pFileLogger;
    QSqlTableModel *m_pModelSql;
    QSqlDatabase m_db;
};
#endif // MAINWINDOW_H
