#include "steamGraphicsItemWithText.h"
#include <qicon.h>

steamGraphicsItemWithText::steamGraphicsItemWithText(QPoint position,QString UserDefName)
{
        QIcon iconMsg =QIcon(":/Icons/Resources/steam32.ico");
        QPixmap pixMap= iconMsg.pixmap(QSize(32, 32),QIcon::Normal, QIcon::On);
        QGraphicsPixmapItem* itemPx=new QGraphicsPixmapItem(pixMap);
        itemPx->setPos(position);
        addToGroup(itemPx);
        QGraphicsTextItem* itemText;
        itemText =new QGraphicsTextItem(UserDefName);
        itemText->setPos(position.x()+40,position.y());
        addToGroup(itemText);


}


steamGraphicsItemWithText::~steamGraphicsItemWithText(void)
{
}

