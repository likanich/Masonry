#include "masonry.h"
#include <QScrollArea>

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
    setItemMinimumWidth(200);
    setItemMaximumWidth(250);
    setSpacingBetweenItems(10);
    setMinimumWidth(itemMinimumWidth() + 2 * spacingBetweenItems());
}

Container::~Container()
{
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
    quint32 x = 0;
    quint32 size = (this->width()-spacingBetweenItems())/(itemMinimumWidth() + spacingBetweenItems());
    quint32 width = (this->width() - (size+1)*spacingBetweenItems())/size;
    if (width > itemMaximumWidth())
        width = itemMaximumWidth();
    quint32 y[size] = {0};

    for(int i = 0; i < items.size(); i++)
    {
        items[i]->setHeightForWidth(width);
        items[i]->setGeometry(x+spacingBetweenItems(), y[i%size]+spacingBetweenItems(), spacingBetweenItems()+ items[i]->width(), spacingBetweenItems()+items[i]->height());
        x=((i+1)%size)*(items[i]->width());
        y[i%size] += items[i]->height();
    }
    quint32 height = y[0];
    for(quint8 i = 0; i < size; i++)
    {
        if (y[i] > height)
            height = y[i];
    }
    setFixedHeight(height + spacingBetweenItems());
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
