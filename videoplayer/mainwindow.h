#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QVideoWidget>
#include <QGraphicsVideoItem>
#include <QFileDialog>
#include <QGraphicsScene>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QMediaPlayer *m_pMediaPlayer;
    QGraphicsVideoItem *m_pVideoItem;
    QString strDurationTime;
    QString strPositionTime;

private slots:
    void onStateChanged(QMediaPlayer::State state);
    void onDurationChanged(qint64 duration);
    void onPositionChanged(qint64 position);
    void on_pushButton_clicked();
};
#endif // MAINWINDOW_H
