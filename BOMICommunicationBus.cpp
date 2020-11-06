#include "BOMICommunicationBus.h"


#include <bominstance.h>
#include <BOMICommunicationBus.h>

using namespace WSIMINST;

BOMICommunicationBus ::BOMICommunicationBus(BOMObject* bomType, int centerX,int centerY,int instanceNumber, QString userDefName):BOMInstance(bomType,centerX,centerY,instanceNumber,userDefName)
//BOMIElectricPrimary ::BOMIElectricPrimary(BOMObject* bomType, int centerX,int centerY,int instanceNumber, QString userDefName)
	{
		//BOMInstance(bomType,centerX,centerY,instanceNumber,userDefName);
		m_BOMType=bomType;
		m_instanceNumber=instanceNumber;
		m_userDefName=userDefName;
		m_Point=QPointF(centerX,centerY);
		int xPos=0,yPos=0;
		bool operateonX=false;
		int bottomX=0,bottomY=0;
		m_Signals= QList<InterfGraphicItem*>();
		   DeviceGraphicItem* item= new DeviceGraphicItem(bomType,0,centerX,centerY,centerX+700);//, centerX+300,centerY);
        addToGroup(item);
        xPos=item->boundingRect().topRight().x();
        yPos=item->boundingRect().topRight().y();
        //text pos
        bottomX=item->boundingRect().bottomRight().x()-60;
        bottomY=item->boundingRect().bottomRight().y();

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
		//to indicate this allows messaging
		setData(1,"message");	


	}


BOMICommunicationBus::~BOMICommunicationBus(void)
{
}
