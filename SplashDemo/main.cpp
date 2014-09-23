#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>
#include <QtTest>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //
    QPixmap pixImg(":/image/trans.png");
    QSplashScreen sc(pixImg.scaled(QSize(700, 700),  Qt::KeepAspectRatio));

    QDateTime n=QDateTime::currentDateTime();
    qApp->processEvents();
    sc.show();
    Qt::Alignment topRight = Qt::AlignLeft | Qt::AlignBottom;
    sc.showMessage(QObject::tr("Setting up the main Window..."),
                    topRight,
                    Qt::blue);
    qApp->processEvents();
    //使用QSplashScreen的过程中发现主线程阻塞的情况下QSplashScreen不发生重绘，只需要加上app.processEvents()

    QDateTime now;
    do{
    now=QDateTime::currentDateTime();
    } while (n.secsTo(now) <= 6); //6需要延时的秒数

    MainWindow w;

    sc.showMessage(QObject::tr("Load..."),
                    topRight,
                    Qt::blue);
    QTest::qSleep(2000);
    qApp->processEvents();

    w.show();
    sc.finish(&w);

    return a.exec();
}
