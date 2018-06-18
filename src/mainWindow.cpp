#include "mainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    masonryWidget = new MasonryWidget(QSize(defaultWidth, defaultHeight));

    scrollArea.setWidget(masonryWidget);
    scrollArea.setWidgetResizable(true);
    scrollArea.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollArea.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    for (quint32 i = 0; i < pixMaps.size();)
    {
        pixMaps[i++].load(QCoreApplication::applicationDirPath() + "/Macrophoto/" + QString::number(i) + ".jpg");
    }

    for (auto &pixMap: pixMaps)
    {
        MasonryItem *lbl = new MasonryItem(pixMap);
        masonryWidget->addItem(lbl);
    }

	setWindowTitle("MasonryWidget Example");
    resize(defaultWidth, defaultHeight);
    setCentralWidget(&scrollArea);   
}

MainWindow::~MainWindow()
{
    delete masonryWidget;
}
