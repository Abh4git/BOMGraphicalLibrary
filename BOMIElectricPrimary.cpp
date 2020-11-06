#include <bominstance.h>
#include <BOMIElectricPrimary.h>
#include <qdir.h>
using namespace WSIMINST;

BOMIElectricPrimary ::BOMIElectricPrimary(BOMObject* bomType, int centerX,int centerY,int instanceNumber, QString userDefName):BOMInstance(bomType,centerX,centerY,instanceNumber,userDefName)
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
		   DeviceGraphicItem* item= new DeviceGraphicItem(bomType,0,centerX,centerY);
        addToGroup(item);
        xPos=item->boundingRect().topRight().x();
        yPos=item->boundingRect().topRight().y();
        //icon
        //QIcon icon1 =QIcon(":/new/icons/Icons/device.ico");
		//QIcon icon1 =QIcon(QPixmap::fromImage(bomType->GetModelIdentification()->GetSceneImage() ));
		//QString fileName= bomType->GetModelIdentification()->GetSceneImageFileName();
		QString fileNameWithExtension= bomType->GetModelIdentification()->GetSceneImageFileNameWithExtension();
		QPixmap pixMap;
		QSize sceneImgSize=bomType->GetModelIdentification()->GetSceneImageSize();
		QString applicationPath=QDir::currentPath() + "//Resources";
		if (fileNameWithExtension.contains(".ico"))
		{
			QIcon iconofScene =QIcon(":/Icons/Resources/"+ fileNameWithExtension);
			
			if (iconofScene.isNull())
			{
				iconofScene= QIcon(applicationPath + "//" + fileNameWithExtension);
			}
			pixMap= iconofScene.pixmap(sceneImgSize,QIcon::Normal, QIcon::On);
		}
		else
		{
			pixMap =  QPixmap(applicationPath + "//" + fileNameWithExtension);
		}
        //QPixmap pixMap= icon1.pixmap(QSize(bomType->GetModelIdentification()->getGlymphList..height(), bomType->GetModelIdentification()->GetSceneImage().width()),QIcon::Normal, QIcon::On);
		//TODO : Hardcoding removal
		//QPixmap pixMap= iconofScene.pixmap(QSize(64, 64),QIcon::Normal, QIcon::On);
		
        QGraphicsPixmapItem* itemPx=new QGraphicsPixmapItem(pixMap);
        itemPx->setPos(centerX-40,centerY-40);
        addToGroup(itemPx);
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
    


	}
BOMIElectricPrimary::	~BOMIElectricPrimary()
	{
	}

BOMObject* BOMIElectricPrimary::GetContainedBOMType()
{
	return BOMInstance::GetContainedBOMType();
}

int BOMIElectricPrimary::GetInstanceNumber()
{
	return BOMInstance::GetInstanceNumber();
}