QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    axbopenglwidget.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    axbopenglwidget.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -LD:/ENV/opencv-4.5.5/build/x64/vc15/lib/ -lopencv_world455
else:win32:CONFIG(debug, debug|release): LIBS += -LD:/ENV/opencv-4.5.5/build/x64/vc15/lib/ -lopencv_world455d
else:unix: LIBS += -LD:/ENV/opencv-4.5.5/build/x64/vc15/lib/ -lopencv_world455

INCLUDEPATH += D:/ENV/opencv-4.5.5/build/include
DEPENDPATH += D:/ENV/opencv-4.5.5/build/include

RESOURCES += \
    res.qrc \
    res.qrc

unix|win32: LIBS += -LD:/ENV/ffmpeg-master-latest-win64-gpl-shared/lib -lavutil -lavformat -lavcodec -lavdevice -lavfilter -lpostproc -lswresample -lswscale

INCLUDEPATH += D:/ENV/ffmpeg-master-latest-win64-gpl-shared/include
DEPENDPATH += D:/ENV/ffmpeg-master-latest-win64-gpl-shared/include
