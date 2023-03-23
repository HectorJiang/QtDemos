#include "mainwindow.h"

#include <QApplication>
#include <Windows.h>
static BOOL enumUserWindowsCB(HWND hwnd, LPARAM lParam)
{
    long wflags = GetWindowLong(hwnd, GWL_STYLE);
    if (!(wflags & WS_VISIBLE)) return TRUE;

    HWND sndWnd;
    if (!(sndWnd = FindWindowEx(hwnd, NULL, L"SHELLDLL_DefView", NULL)))
        return TRUE;

    HWND targetWnd;
    if (!(targetWnd = FindWindowEx(sndWnd, NULL, L"SysListView32", L"FolderView")))
        return TRUE;

    HWND* resultHwnd = (HWND*)lParam;
    *resultHwnd = targetWnd;
    //*resultHwnd = hwnd;//set to workerW
    return FALSE;
}

HWND findDesktopIconWnd()
{
    HWND resultHwnd = NULL;
    EnumWindows((WNDENUMPROC)enumUserWindowsCB, (LPARAM)&resultHwnd);
    return resultHwnd;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    HWND hdesktop = findDesktopIconWnd();
//    WId wid = w.winId();
//    SetParent((HWND)wid, hdesktop);
    w.show();
    return a.exec();
}
