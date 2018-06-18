#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include "elemUI/masonryWidget.h"
#include <array>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    MasonryWidget *masonryWidget;
    QScrollArea scrollArea;
    std::array<QPixmap, 100> pixMaps;

    const quint32 defaultWidth = 1200;
    const quint32 defaultHeight = 600;
};

#endif // MAINWINDOW_H
