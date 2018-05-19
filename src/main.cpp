#include "mainwindow.h"
#include "masonry.h"
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    QWidget wgt;

    masonry::Container *container = new masonry::Container(QSize(800,700));
    QScrollArea scrollArea;
    scrollArea.setWidget(container);
    //scrollArea.setWidgetResizable(true);
    //scrollArea.setParent(&wgt);
    QPixmap pix[100];
    for (int i = 1; i < 100; i++)
    {
        pix[i].load("./Macrophoto/" + QString::number(i) + ".jpg");
    }

    //masonry::Item lbl[100];
    for (int i = 1; i < 100; i++)
    {
        masonry::Item *lbl = new masonry::Item(pix[i]);
        container->addItem(lbl);
    }
    //wgt.resize(scrollArea.size());
    //wgt.show();
    scrollArea.resize(QSize(container->width(),500));
    scrollArea.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollArea.show();
    //container->show();
    return a.exec();
}
