#pragma once

#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include "masonry.h"

class MasonryItem : public QLabel, public masonry::Item
{
	Q_OBJECT
public:
	explicit MasonryItem(const QPixmap &pixmap);
    virtual ~MasonryItem();
	
	virtual quint32 heightForWidth(quint32 width);
    virtual void setGeometry(const QRect &geometry)
    {
        _geometry = geometry;
        QLabel::setGeometry(geometry);
        setPixmap(_pixmap.scaledToWidth(size().width()));
    }


private:
	QPixmap _pixmap;

};

class MasonryWidget : public QWidget
{
public:
	explicit MasonryWidget(QWidget *parent, const QSize &size);
	explicit MasonryWidget(const QSize &size);
	~MasonryWidget();

    void addItem(MasonryItem *item);

	virtual void resizeEvent(QResizeEvent *event);

private:
	masonry::Container *container;
};
