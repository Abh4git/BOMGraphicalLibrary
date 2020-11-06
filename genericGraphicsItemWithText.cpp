#include "genericGraphicsItemWithText.h"
#include <qicon.h>

genericGraphicsItemWithText::genericGraphicsItemWithText(QPoint position,QString UserDefName,QString iconName )
{
        QString iconPath= ":/Icons/Resources/" ;
        QIcon iconMsg = QIcon(iconPath+iconName);  //QIcon(":/Icons/Resources/elecsignal32.ico");
        QPixmap pixMap= iconMsg.pixmap(QSize(32, 32),QIcon::Normal, QIcon::On);
        QGraphicsPixmapItem* itemPx=new QGraphicsPixmapItem(pixMap);
        itemPx->setPos(position);
        addToGroup(itemPx);
        QGraphicsTextItem* itemText;
        itemText =new QGraphicsTextItem(UserDefName);
        itemText->setPos(position.x()+40,position.y());
        addToGroup(itemText);


}


genericGraphicsItemWithText::~genericGraphicsItemWithText(void)
{
}


