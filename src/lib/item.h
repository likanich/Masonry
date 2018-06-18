#pragma once
#include <QObject>
#include <QRect>

namespace masonry
{
    // Abstract representation of element to be displayed.
    class Item : public QObject
    {
        Q_OBJECT
    public:
        virtual ~Item()=0;

        // Returns height for given width.
        // Must be implemented by Item inheritor.
        virtual quint32 heightForWidth(quint32 width) = 0;

        // Returns Item geometry relative to container.
        // Called by Item inheritor to get the updated geometry after
        // container has changed it and notified Item via the geometryChanged signal.
        QRect itemGeometry() const
        {
            return _geometry;
        }
        // Called by Container whenever it changes the Item geometry.
        void setGeometry(const QRect &geometry)
        {
                _geometry = geometry;
                emit geometryChanged();
        }

    signals:
        //Container emits this signal when Item geometry has been changed
        void geometryChanged();
    private:
        QRect _geometry;
    };
}
