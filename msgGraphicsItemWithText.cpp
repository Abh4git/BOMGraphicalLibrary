#include "msgGraphicsItemWithText.h"
#include <qicon.h>

msgGraphicsItemWithText::msgGraphicsItemWithText(QPoint position,QString UserDefName)
{
		QIcon iconMsg =QIcon(":/Icons/Resources/msgpacket48.ico");
        QPixmap pixMap= iconMsg.pixmap(QSize(48, 48),QIcon::Normal, QIcon::On);
        QGraphicsPixmapItem* itemPx=new QGraphicsPixmapItem(pixMap);
        itemPx->setPos(position);
        addToGroup(itemPx);
		QGraphicsTextItem* itemText;
		itemText =new QGraphicsTextItem(UserDefName);
		itemText->setPos(position.x()+40,position.y());
		addToGroup(itemText);
		
    
}


msgGraphicsItemWithText::~msgGraphicsItemWithText(void)
{
}
