#include <DApplication>
#include <DMainWindow>
#include <DWidgetUtil>
#include "mainwindow.h"

DWIDGET_USE_NAMESPACE

int main(int argc, char *argv[])
{
    DApplication::loadDXcbPlugin();
    DApplication a(argc, argv);

    MainWindow w;
    w.setFixedSize(360,320);
//    w.setAttribute(Qt::WA_TranslucentBackground);
    w.show();
    Dtk::Widget::moveToCenter(&w);

    return a.exec();
}
