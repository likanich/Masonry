#pragma once
#include <QtGlobal>
#include <QSize>
#include <vector>
#include "item.h"

namespace masonry
{
	class Container
	{
	public:
		// Ctor accepts initial container size.
		explicit Container(const QSize &size);
		~Container();

		// Sets new container size.
		void setContainerSize(const QSize &size);

		// Sets fixed vertical/horizontal spacing between the items.
		void setSpacingBetweenItems(quint32 spacing);

		// Specifies the min/max values for Item width.
		void setItemMinimumWidth(const quint32 width);
		void setItemMaximumWidth(const quint32 width);
		void setFixedContainerHeight(const quint32 height);

		quint32 containerWidth() const;
		quint32 spacingBetweenItems() const;
		quint32 itemMinimumWidth() const;
		quint32 itemMaximumWidth() const;
		quint32 fixedContainerHeight() const;

		// Adds Item to the end of container.
		void addItem(Item *item);

		// Removes Item from container.
		void removeItem(Item *item);

		// Returns ordered list of stored Items
		std::vector<Item *> items() const;

		// Recalculates geometry of all items
		void update();

	private:
		class Impl;
		Impl *_impl;

		QSize _size;
		quint32 _itemMinimumWidth = 200;
		quint32 _itemMaximumWidth = 250;
		quint32 _spacingBetweenItems = 10;
		quint32 _fixedContainerHeight;

		std::vector<Item *> _items;
	};

}
