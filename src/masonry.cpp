#include "masonry.h"
#include <QScrollArea>
#include <QDebug>

using namespace masonry;

Container::Container(QWidget *parent, const QSize &size)
    : QWidget(parent)
{
    setContainerSize(size);
    setSpacingBetweenItems(200);
    setMinimumSize(200,200);
}

Container::Container(const QSize &size)
{
    setContainerSize(size);
    setMinimumSize(200,200);
    setItemMinimumWidth(200);
    setItemMaximumWidth(250);
    setSpacingBetweenItems(10);
}

Container::~Container()
{
    //items.removeAll();
}

void Container::addItem(Item *item)
{
    item->setParent(this);
    items.append(item);
    update();
}

void Container::setContainerSize(const QSize &size)
{
    resize(size);
}

void Container::update()
{
    int x = 0;
    int size = (this->width()-spacingBetweenItems())/(itemMinimumWidth() + spacingBetweenItems());
    quint32 width = (this->width() - (size+1)*spacingBetweenItems())/size;
    if (width > itemMaximumWidth())
        width = itemMaximumWidth();
    int y[size] = {0};
    int sbi = 10;


    for(int i = 0; i < items.size(); i++)
    {
        items[i]->setHeightForWidth(width);
        items[i]->setGeometry(x+sbi, y[i%size]+sbi, sbi+ items[i]->width(), sbi+items[i]->height());
        x=((i+1)%size)*(items[i]->width());
        y[i%size] += items[i]->height();
    }
}

quint32 Container::spacingBetweenItems() const
{
    return spacingBetweenItem;
}

quint32 Container::itemMaximumWidth() const
{
    return maximumWidth;
}

quint32 Container::itemMinimumWidth() const
{
    return minimumWidth;
}

void Container::resizeEvent(QResizeEvent *event)
{
    qDebug() << "Resize";
    update();
}

void Container::setItemMinimumWidth(quint32 width)
{
    minimumWidth = width;
}
void Container::setItemMaximumWidth(quint32 width)
{
    maximumWidth = width;
}

Item::Item(const QPixmap &pixmap, QWidget *parent) : QLabel(parent)
{
    this->pixmap = pixmap;
    setHeightForWidth(200);
}

void Item::setHeightForWidth(int width)
{
    this->resize(pixmap.scaledToWidth(width).size());
    this->setPixmap(pixmap.scaledToWidth(width));
}
