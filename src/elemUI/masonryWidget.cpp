#include "masonryWidget.h"

MasonryWidget::MasonryWidget(const QSize & size, const quint32 itemMinimumWidth, const quint32 itemMaximumWidth, const quint32 spacingBetweenItems)
{
	container = new masonry::Container(size);
	container->setItemMinimumWidth(itemMinimumWidth);
	container->setItemMaximumWidth(itemMaximumWidth);
	container->setSpacingBetweenItems(spacingBetweenItems);
	resize(size);
	setMinimumWidth(container->spacingBetweenItems() * 2 + container->itemMinimumWidth());
}

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