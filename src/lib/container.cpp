#include "container.h"

masonry::Container::Container(const QSize & size)
{
	setContainerSize(size);
}

masonry::Container::~Container()
{
}

void masonry::Container::setContainerSize(const QSize & size)
{
	_size = size;
}

void masonry::Container::setSpacingBetweenItems(quint32 spacing)
{
	_spacingBetweenItems = spacing;
}

void masonry::Container::setItemMinimumWidth(quint32 width)
{
	_itemMinimumWidth = width;
}

void masonry::Container::setItemMaximumWidth(quint32 width)
{
	_itemMaximumWidth = width;
}

void masonry::Container::setFixedContainerHeight(quint32 height)
{
	_fixedContainerHeight = height;
}

quint32 masonry::Container::containerWidth() const
{
	return _size.width();
}

quint32 masonry::Container::spacingBetweenItems() const
{
	return _spacingBetweenItems;
}

quint32 masonry::Container::itemMinimumWidth() const
{
	return _itemMinimumWidth;
}

quint32 masonry::Container::itemMaximumWidth() const
{
	return _itemMaximumWidth;
}

quint32 masonry::Container::fixedContainerHeight() const
{
	return _fixedContainerHeight;
}

void masonry::Container::addItem(Item * item)
{
	_items.push_back(item);
}

void masonry::Container::removeItem(Item * item)
{
}

std::vector<masonry::Item*> masonry::Container::items() const
{
	return std::vector<Item*>();
}

void masonry::Container::update()
{
    quint32 x = 0;
	const quint32 size = (containerWidth() - spacingBetweenItems()) / (itemMinimumWidth() + spacingBetweenItems());
	quint32 width = (containerWidth() - (size + 1)*spacingBetweenItems()) / size;
	if (width > itemMaximumWidth())
		width = itemMaximumWidth();
	quint32 *y = new quint32[size];
	for (quint32 i = 0; i < size; i++)
	{
		y[i] = { 0 };
	}
	for (quint32 i = 0; i < _items.size(); i++)
	{
        QRect itemGeometry(x + spacingBetweenItems(),
						   y[i%size] + spacingBetweenItems(), 
                           width,
                           _items[i]->heightForWidth(width));

		_items[i]->setGeometry(itemGeometry);

        x = ((i + 1) % size)*(width+spacingBetweenItems());
        y[i%size] += _items[i]->heightForWidth(width) + spacingBetweenItems();
	}
	quint32 height = y[0];
	for (quint8 i = 0; i < size; i++)
	{
		if (y[i] > height)
			height = y[i];
	}
	setFixedContainerHeight(height + spacingBetweenItems());
}
