#include "BOMISecondary.h"

using namespace WSIMINST;
BOMISecondary::BOMISecondary(BOMObject* bomType, int centerX,int centerY,int instanceNumber, QString userDefName):BOMInstance(bomType,centerX,centerY,instanceNumber,userDefName)
{
	m_BOMType=bomType;
		m_instanceNumber=instanceNumber;
		m_userDefName=userDefName;
		m_Point=QPointF(centerX,centerY);
		int xPos=0,yPos=0;
		bool operateonX=false;
		int bottomX=0,bottomY=0;
		m_Signals= QList<InterfGraphicItem*>();
		   DeviceGraphicItem* item= new DeviceGraphicItem(bomType,0,centerX,centerY);
        addToGroup(item);
        xPos=item->boundingRect().topRight().x();
        yPos=item->boundingRect().topRight().y();
        //icon
		//QIcon icon1 =QIcon(QPixmap::fromImage(bomType->GetModelIdentification()->GetSceneImage() ));
		QString fileName= bomType->GetModelIdentification()->GetSceneImageFileName();
		QIcon icon1 =QIcon(":/Icons/Resources/"+ fileName + ".ico");
        //QPixmap pixMap= icon1.pixmap(QSize(bomType->GetModelIdentification()->.height(), bomType->GetModelIdentification()->GetSceneImage().width()),QIcon::Normal, QIcon::On);
		//TODO : Hardcoding removal
		QPixmap pixMap= icon1.pixmap(QSize(64, 64),QIcon::Normal, QIcon::On);
        QGraphicsPixmapItem* itemPx=new QGraphicsPixmapItem(pixMap);
        itemPx->setPos(centerX-40,centerY-40);
        addToGroup(itemPx);
        //text pos
        bottomX=item->boundingRect().bottomRight().x()-60;
        bottomY=item->boundingRect().bottomRight().y();

		//interfaces
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
    
		//text here
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
		setFlag(QGraphicsItem::ItemIsMovable, true);
		setFlag(QGraphicsItem::ItemIsSelectable, true);
		setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
    
}


BOMISecondary::~BOMISecondary(void)
{
}
