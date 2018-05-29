#pragma once
#include <QtGlobal>
#include <QObject>
#include <QSize>
#include <QRect>
#include <vector>

namespace masonry
{
	// Abstract representation of element to be displayed.
    class Item
	{
	public:
		virtual ~Item()=0;

		// Returns height for given width.
		// Must be implemented by Item inheritor.
		virtual quint32 heightForWidth(quint32 width) = 0;

		// Returns Item geometry relative to container.
		// Called by Item inheritor to get the updated geometry after
		// container has changed it and notified Item via the geometryChanged signal.
		virtual QRect geometry() const
		{
			return _geometry;
		}

		// Called by Container whenever it changes the Item geometry.
		virtual void setGeometry(const QRect &geometry)
		{
			_geometry = geometry;
			emit geometryChanged();
		}

	signals:
		// Container emits this signal when Item geometry has been changed
		void geometryChanged();

	//protected:
		QRect _geometry;
	};

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
		void setItemMinimumWidth(quint32 width);
		void setItemMaximumWidth(quint32 width);
		void setFixedContainerHeight(quint32 height);

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
