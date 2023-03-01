#include "mainwindow.h"

#include <QApplication>
#include <opencv2/opencv.hpp>
extern "C"
{
    #include <libavcodec/avcodec.h>
    #include <libavformat/avformat.h>
    #include <libswscale/swscale.h>
    #include <libavdevice/avdevice.h>
    #include <libavformat/version.h>
    #include <libavutil/time.h>
    #include <libavutil/mathematics.h>
    #include <libavfilter/buffersink.h>
    #include <libavfilter/buffersrc.h>
    #include <libavutil/avutil.h>
    #include <libavutil/imgutils.h>
    #include <libavutil/pixfmt.h>
    #include <libswresample/swresample.h>
}
#include <QtDebug>
using namespace cv;
int main(int argc, char *argv[])
{
//    Mat img = imread("C:\\Users\\HectorJiang\\Desktop\\QtDemos\\framework\\images\\img.png");
//    imshow("win", img);
    qDebug(avcodec_configuration());
    unsigned version = avcodec_version();
    QString ch = QString::number(version, 10);
    qDebug()<<"version:"<<version;
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
