#include "masonryItem.h"
#include <math.h>

MasonryItem::MasonryItem(const QPixmap & pixmap)
	: _pixmap(pixmap)
{
    _label = new QLabel();
    _label->resize(pixmap.size());
    _label->setPixmap(pixmap);
    QObject::connect(this, SIGNAL(geometryChanged()), SLOT(setLabelGeometry()));
}

MasonryItem::~MasonryItem()
{
    delete _label;
}

quint32 MasonryItem::heightForWidth(quint32 width)
{
    return round((double)_label->size().height() * width / (double)_label->size().width());
}

void MasonryItem::setParent(QWidget *parent)
{
    _label->setParent(parent);
}

void MasonryItem::setLabelGeometry()
{
    _label->setGeometry(itemGeometry());
    _label->setPixmap(_pixmap.scaledToWidth(_label->size().width()));
}