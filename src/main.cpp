// masonry.cpp:
//
#include <QtWidgets>
#include "masonryWidget.h"

int main(int argc, char** argv)
{
	QApplication a(argc, argv);

    MasonryWidget *masonryWidget = new MasonryWidget(QSize(800, 100));
	QScrollArea scrollArea;
	scrollArea.setWidgetResizable(true);
	scrollArea.setWidget(masonryWidget);

	QPixmap pix[100];
    for (int i = 1; i <= 100; ++i)
	{
        pix[i-1].load(QCoreApplication::applicationDirPath() + "/Macrophoto/" + QString::number(i) + ".jpg");
	}
    for (int i = 0; i < 100; ++i)
	{

        MasonryItem *lbl = new MasonryItem(pix[i]);

		masonryWidget->addItem(lbl);
	}

	scrollArea.resize(QSize(masonryWidget->width(), 500));
	scrollArea.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	scrollArea.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    scrollArea.show();

	return a.exec();
}
