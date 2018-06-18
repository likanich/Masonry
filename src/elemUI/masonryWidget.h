#pragma once

#include <QWidget>
#include "lib/container.h"
#include "masonryItem.h"

class MasonryWidget : public QWidget
{
public:
	explicit MasonryWidget(const QSize &size, const quint32 itemMinimumWidth, const quint32 itemMaximumWidth, const quint32 spacingBetweenItems);
	explicit MasonryWidget(QWidget *parent, const QSize &size);
	explicit MasonryWidget(const QSize &size);
	~MasonryWidget();

    void addItem(MasonryItem *item);

	void resizeEvent(QResizeEvent *event);

private:
	masonry::Container *container;
};
