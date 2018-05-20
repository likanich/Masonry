#include <QWidget>
#include <QLabel>
#include <QPixmap>
//#include <vector>

namespace masonry
{
    // Abstract representation of element to be displayed.
    class Item : public QLabel
    {
    public:
        explicit Item(const QPixmap &pixmap, QWidget *parent = 0);
        //~Item() = 0;

        void setHeightForWidth(int width);

    private:
        QPixmap pixmap;
    };

    class Container : public QWidget
    {
    public:
        // Ctor accepts initial container size.
        explicit Container(QWidget *parent, const QSize &size);
        explicit Container(const QSize &size);
        ~Container();

        // Sets new container size.
        void setContainerSize(const QSize &size);

        // Sets fixed vertical/horizontal spacing between the items.
        void setSpacingBetweenItems(quint32 spacing)
        {
            spacingBetweenItem = spacing;
        }

        // Specifies the min/max values for Item width.
        void setItemMinimumWidth(quint32 width);
        void setItemMaximumWidth(quint32 width);

        quint32 spacingBetweenItems() const;
        quint32 itemMinimumWidth() const;
        quint32 itemMaximumWidth() const;

        // Adds Item to the end of container.
        void addItem(Item *item);

//		// Removes Item from container.
//		void removeItem(Item *item);

//		// Returns ordered list of stored Items
//		std::vector<Item *> items() const;

        // Recalculates geometry of all items
        void update();
    signals:
        virtual void resizeEvent(QResizeEvent *event);
    private:
        QList<Item *> items;

//        std::vector<Item *> items;
        quint32 minimumWidth;
        quint32 maximumWidth;
        quint32 spacingBetweenItem;
    };
}
