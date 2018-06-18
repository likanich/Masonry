#pragma once

#include <QLabel>
#include <QPixmap>
#include "lib/item.h"

class MasonryItem : public masonry::Item
{
	Q_OBJECT
public:
    explicit MasonryItem(const QPixmap &pixmap);
	~MasonryItem() override;

	quint32 heightForWidth(quint32 width) override;

	void setParent(QWidget *parent);

public slots:
    void setLabelGeometry();

private:
	QPixmap _pixmap;
    QLabel *_label;
};