#include "bomfactory.h"
#include <BOMIElectricPrimary.h>

#include <BOMICommunicationBus.h>
#include <BOMIUser.h>
#include <BOMIEquipment.h>
#include <connectorgraphicitem.h>
#include <msgGraphicsItemWithText.h>
#include <ActionGraphicsItem.h>
BOMInstance* BOMFactory::createBOMInstance(BOMObject* typeofBOM, int centerXPos,int centerYPos,QString userDefName)
{
	BOMIElectricPrimary* bomElecPrim;
	BOMICommunicationBus* bomCommBus;
	BOMInstance* bomCreatedInstance;
	if (typeofBOM->GetModelIdentification()->GetBOMType()==1)
	{
		
		//bomElecPrim= new BOMIElectricPrimary(typeofBOM,centerXPos,centerYPos,1,userDefName);
		bomCreatedInstance= new BOMIElectricPrimary(typeofBOM,centerXPos,centerYPos,1,userDefName);
		//return bomElecPrim;
	} else if(typeofBOM->GetModelIdentification()->GetBOMType()==2)
	{
		bomCreatedInstance = new BOMICommunicationBus(typeofBOM,centerXPos,centerYPos,1,userDefName);
		//return bomCommBus;
	} else if(typeofBOM->GetModelIdentification()->GetBOMType()==3)
	{
		bomCreatedInstance = new BOMIUser(typeofBOM,centerXPos,centerYPos,1,userDefName);
		//return bomCommBus;
	}else if(typeofBOM->GetModelIdentification()->GetBOMType()==4)
	{
		bomCreatedInstance = new BOMIEquipment(typeofBOM,centerXPos,centerYPos,1,userDefName);
		//return bomCommBus;
	}  

	return bomCreatedInstance;
}

ConnectorGraphicitem* BOMFactory::createConnector(int startX,int startY, int endX,int endY, QString UserDefName)
{
	return new ConnectorGraphicitem(UserDefName, 0,0,QPoint(startX,startY),QPoint(endX,endY));
}

MsgGraphicsItem* BOMFactory::createMessagePacket(QPoint position)
{
	QIcon iconMsg =QIcon(":/Icons/Resources/msgpacket48.ico");
    QPixmap pixMap= iconMsg.pixmap(QSize(48, 48),QIcon::Normal, QIcon::On);
	
	return new MsgGraphicsItem(pixMap);
}

genericGraphicsItemWithText* BOMFactory::createGenericGraphicItemWithText(QPoint position, QString UserDefName, QString iconName)
{
    return new genericGraphicsItemWithText(position,UserDefName,iconName);
}

msgGraphicsItemWithText* BOMFactory:: createMessagePacketTxt(QPoint position,QString UserDefname)
{
	return new msgGraphicsItemWithText(position,UserDefname);
}
ActionGraphicsItem* BOMFactory:: createActionSignal(QPoint position)
{
	QIcon iconMsg =QIcon(":/Icons/Resources/action48.ico");
    QPixmap pixMap= iconMsg.pixmap(QSize(48, 48),QIcon::Normal, QIcon::On);
	
	return new ActionGraphicsItem(pixMap);
}

signalGraphicsItemWithText* BOMFactory:: createSignalWithText(QPoint position,QString UserDefname)
{
    return new signalGraphicsItemWithText(position,UserDefname);
}

steamGraphicsItemWithText* BOMFactory:: createHeatSteamTransferWithText(QPoint position,QString UserDefname)
{
    return new steamGraphicsItemWithText(position,UserDefname);
}

QGraphicsTextItem* BOMFactory::createHighLightedText(QPoint position,QString valueText)
{
	QGraphicsTextItem* itemTxt= new QGraphicsTextItem();
	itemTxt->setPlainText(valueText);
	itemTxt->setDefaultTextColor(QColor::Cmyk);
	
	itemTxt->setFont(QFont("Arial",3, QFont::Bold));
	itemTxt->setHtml(QString("<div style='background-color: #ffff00;'>"));
	itemTxt->setPos(position);
	return itemTxt;
}

Q_PLUGIN_METADATA(BOMFACTORY_LIB::BOMFactory)
//Q_EXPORT_PLUGIN2(BOMFACTORY_LIB, BOMFactory)


