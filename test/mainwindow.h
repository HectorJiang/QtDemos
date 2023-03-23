#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QMouseEvent>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void mouseMoveEvent(QMouseEvent *e);
    void moveEvent(QMoveEvent *e);
    void resizeEvent(QResizeEvent *e);
private:
    Ui::MainWindow *ui;
    QLabel *m_pLbPos;
    QLabel *m_pLbImg;
};
#endif // MAINWINDOW_H
