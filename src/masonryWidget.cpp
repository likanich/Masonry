#include "masonryWidget.h"
#include <math.h> 
#include "QDebug"

MasonryWidget::MasonryWidget(QWidget * parent, const QSize & size)
	: QWidget(parent)
{
	resize(size);
	container = new masonry::Container(size);
	setMinimumWidth(container->spacingBetweenItems() * 2 + container->itemMinimumWidth());
}

MasonryWidget::MasonryWidget(const QSize & size) 
{
	resize(size);
	container = new masonry::Container(size);
	setMinimumWidth(container->spacingBetweenItems() * 2 + container->itemMinimumWidth());
}

MasonryWidget::~MasonryWidget()
{
    delete container;
}

void MasonryWidget::addItem(MasonryItem *item)
{
    item->setParent(this);
	container->addItem(item);
	container->update();
	setFixedHeight(container->fixedContainerHeight());
    update();
}

void MasonryWidget::resizeEvent(QResizeEvent *event)
{
	container->setContainerSize(size());
	container->update();
    setFixedHeight(container->fixedContainerHeight());
    update();
}



MasonryItem::MasonryItem(const QPixmap & pixmap)
	: _pixmap(pixmap)
{
    resize(pixmap.size());
    setPixmap(pixmap);
}

MasonryItem::~MasonryItem()
{
}

quint32 MasonryItem::heightForWidth(quint32 width)
{
    
    return round((double)size().height() * width / (double)size().width());
}


