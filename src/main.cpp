#include "masonry.h"
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    masonry::Container *container = new masonry::Container(QSize(800,3700));
    QScrollArea scrollArea;
    scrollArea.setWidgetResizable(true);
    scrollArea.setWidget(container);

    QPixmap pix[100];
    for (int i = 1; i < 100; i++)
    {
        pix[i].load(QCoreApplication::applicationDirPath() + "/Macrophoto/" + QString::number(i) + ".jpg");
    }

    for (int i = 1; i < 100; i++)
    {
        masonry::Item *lbl = new masonry::Item(pix[i]);
        container->addItem(lbl);
    }

    scrollArea.resize(QSize(container->width(),500));
    scrollArea.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollArea.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    scrollArea.show();

    return a.exec();
}
