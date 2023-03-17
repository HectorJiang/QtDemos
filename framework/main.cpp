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
#include <iostream>
using namespace cv;
int main(int argc, char *argv[])
{
//    namedWindow("cap", WINDOW_AUTOSIZE);
//    VideoCapture cap;
//    cap.open(0);
//    if(!cap.isOpened()) std::cerr<<"couldn't open capture"<<std::endl;
//    Mat img;
//    while(true){
//        cap>>img;
//        if(img.empty()) break;
//        imshow("cap", img);
//        if(waitKey(33)>=0) break;
//    }
//    cap.open("C:\\Users\\HectorJiang\\Desktop\\QtDemos\\framework\\videos\\demo.mp4");
//    Mat img1 = imread("C:\\Users\\HectorJiang\\Desktop\\QtDemos\\framework\\images\\img.png");
//    namedWindow("img1", WINDOW_AUTOSIZE);
//    namedWindow("img2", WINDOW_AUTOSIZE);
//    imshow("img1", img1);
//    Mat img2;
//    cvtColor(img1, img2, COLOR_BGR2GRAY);
//    GaussianBlur(img1, img2, Size(5,5), 3, 3);
//    GaussianBlur(img2, img2, Size(5,5), 3, 3);
//    imshow("img2", img2);
//    waitKey(0);
//    namedWindow("img", WINDOW_AUTOSIZE);
//    imshow("win", img);
//    waitKey(0);
//    qDebug(avcodec_configuration());
//    unsigned version = avcodec_version();
//    QString ch = QString::number(version, 10);
//    qDebug()<<"version:"<<version;
//    AVFormatContext *pFormatContext = avformat_alloc_context();
//    const char * filename = "C:\\Users\\HectorJiang\\Desktop\\demo.mp4";
//    avformat_open_input(&pFormatContext, filename, NULL, NULL);
//    printf("Format %s, duration %lld us", pFormatContext->iformat->long_name, pFormatContext->duration);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
