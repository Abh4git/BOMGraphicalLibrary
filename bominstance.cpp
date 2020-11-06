#include "bominstance.h"

 #include <QWidget>
#include <QtPlugin>
#include <qpixmap.h>

 //Q_IMPORT_PLUGIN(BOMOBJECT_H)


using namespace WSIMINST;


BOMInstance::BOMInstance(BOMObject* bomType, int startX, int startY,int instanceNumber,QString userDefName)
{
    m_BOMType=bomType;
    m_instanceNumber=instanceNumber;
	m_userDefName=userDefName;
    m_Point=QPointF(startX,startY);
    int xPos=0,yPos=0;
    bool operateonX=false;
    int bottomX=0,bottomY=0;
    m_Signals= QList<InterfGraphicItem*>();
    if (bomType->GetModelIdentification()->GetBOMType()!=2)
    {
        DeviceGraphicItem* item= new DeviceGraphicItem(bomType,0,startX,startY);
        addToGroup(item);
        xPos=item->boundingRect().topRight().x();
        yPos=item->boundingRect().topRight().y();
        //icon
        //QIcon icon1 =QIcon(":/new/icons/Icons/device.ico");
		QIcon icon1 =QIcon(QPixmap::fromImage(bomType->GetModelIdentification()->GetSceneImage() ));
        QPixmap pixMap= icon1.pixmap(QSize(bomType->GetModelIdentification()->GetSceneImage().height(), bomType->GetModelIdentification()->GetSceneImage().width()),QIcon::Normal, QIcon::On);
        QGraphicsPixmapItem* itemPx=new QGraphicsPixmapItem(pixMap);
        itemPx->setPos(startX-40,startY-40);
        addToGroup(itemPx);
        //text pos
        bottomX=item->boundingRect().bottomRight().x()-60;
        bottomY=item->boundingRect().bottomRight().y();


    //} 
    
	foreach(Interface* inf,m_BOMType->GetInterfaces())
    {
        if(inf->GetExternal()==true)
        {
        InterfGraphicItem* itemInf= new InterfGraphicItem(inf,0,xPos,yPos);
        itemInf->setData(1,inf->GetName());
        itemInf->setToolTip(inf->GetName());
        addToGroup(itemInf);
        m_Signals.append(itemInf);
        QGraphicsTextItem* interfaceText=new QGraphicsTextItem(inf->GetName().left(8));

        interfaceText->setPos(xPos,yPos);
        addToGroup(interfaceText);

        if (operateonX)
        {
            xPos=xPos+20;
        }
            else
        {
            yPos=yPos+20;
        }

        }

    }
	}
	/* comment for now
    QGraphicsTextItem* itemText;
		if (m_userDefName=="")
		{

			itemText =new QGraphicsTextItem(bomType->GetModelIdentification()->GetName() + ":" + QString::number(instanceNumber));
		} else
		{
			itemText =new QGraphicsTextItem(m_userDefName + ":" + QString::number(instanceNumber));
		}

    itemText->setPos(bottomX+50,bottomY-30);
    addToGroup(itemText);
	*/
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
    //connect(this, SIGNAL(objectSelected(BOMObject*)),this->parentObject(),SLOT(this->parentObject()->childrenChanged())
}

InterfGraphicItem* BOMInstance::FindSignal(QString signalName)
{
    foreach(InterfGraphicItem* inf, this->m_Signals)
    {
        if (inf->data(1).toString()==signalName)
        {
            return inf;
        }
    }
}

/*BOMObject* BOMInstance::GetContainedBOMType()
{
    return m_BOMType;
}

int BOMInstance::GetInstanceNumber()
{
    return m_instanceNumber;
}

QPointF BOMInstance::GetPosition()
{
    return m_Point;
} */

void BOMInstance::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    //show the details in view
    //emit objectSelected(this->m_BOMType);

}

void BOMInstance::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{

}



