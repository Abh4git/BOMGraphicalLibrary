#include "devicegraphicitem.h"

using namespace WSIMINST;
DeviceGraphicItem::DeviceGraphicItem   (QGraphicsItem *parent):
    QGraphicsPolygonItem(parent)
{

    deviceGraphic << QPointF(_startX-40, _startY-40) << QPointF(_startX+40, _startY -40)
                  << QPointF(_startX+40, _startY+40) << QPointF(_startX-40,_startY +40)
                  << QPointF(_startX-40, _startY-40);
    setPolygon(deviceGraphic);
        setFlag(QGraphicsItem::ItemIsMovable, true);
        setFlag(QGraphicsItem::ItemIsSelectable, true);
        setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);

}

DeviceGraphicItem::DeviceGraphicItem(QGraphicsItem *parent, int startX, int startY)
{
    this->_startX=startX;
    this->_startY=startY;
    deviceGraphic << QPointF(_startX-40, _startY-40) << QPointF(_startX+40, _startY -40)
                  << QPointF(_startX+40, _startY+40) << QPointF(_startX-40,_startY +40)
                  << QPointF(_startX-40, _startY-40);
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
    QPen pen(Qt::blue, 2);
    setPen(pen);
    QBrush brush(Qt::yellow);
    setBrush(brush);

    setPolygon(deviceGraphic);
}

DeviceGraphicItem::DeviceGraphicItem(BOMObject *typeOfBOM, QGraphicsItem *parent, int startX, int startY,int endX)
{
    this->_startX=startX;
    this->_startY=startY;
    /*deviceGraphic << QPointF(_startX-40, _startY-40) << QPointF(_startX+40, _startY -40)
                  << QPointF(_startX+40, _startY+40) << QPointF(_startX-40,_startY +40)
                  << QPointF(_startX-40, _startY-40);*/
	if (endX==0)
	{
    deviceGraphic << QPointF(_startX-40, _startY-40) << QPointF(_startX+25, _startY -40)
                  << QPointF(_startX+25, _startY+25) << QPointF(_startX-40,_startY +25)
                  << QPointF(_startX-40, _startY-25);
	} else
	{
		deviceGraphic << QPointF(_startX, _startY) << QPointF(endX, _startY)
                  << QPointF(endX, _startY+5) << QPointF(_startX,_startY +5)
                  << QPointF(_startX, _startY);
    
	}
	setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
    QPen pen(Qt::white, 2);
    setPen(pen);
    //QBrush brush(Qt::lightGray);
	//QBrush brush(Qt::lightGray);
	QBrush brush(Qt::white);
    setBrush(brush);

    setPolygon(deviceGraphic);
    this->m_BOMType=typeOfBOM;
}

//new

/*
DeviceGraphicItem::DeviceGraphicItem(BOMObject* typeOfBOM,QGraphicsItem *parent ,int startX, int startY,int endX,int endY)

{
	this->_startX=startX;
    this->_startY=startY;
   
    deviceGraphic << QPointF(_startX, _startY) << QPointF(endX, _startY)
                  << QPointF(endX, _startY+5) << QPointF(_startX,_startY +5)
                  << QPointF(_startX, _startY);
    
	setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
    QPen pen(Qt::black, 2);
    setPen(pen);
    QBrush brush(Qt::lightGray);
    setBrush(brush);

    setPolygon(deviceGraphic);
    this->m_BOMType=typeOfBOM;

}*/

/*
void DeviceGraphicItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    int currentY=0;


    painter->setRenderHint(QPainter::Antialiasing, true);
    QPen pen(Qt::blue, 2);
    painter->setPen(pen);
    QBrush brush1(Qt::white);
    painter->setBrush(brush1);

    //painter->drawPolygon(deviceGraphic);
    QBrush brush(Qt::green);
    painter->setBrush(brush);

    QIcon icon=this->_typeOfDevice->GetIcon();
    QPixmap px= icon.pixmap(QSize(32,32),QIcon::Normal,QIcon::On);

    painter->drawPixmap(_startX-30,_startY-30,px);
    currentY=_startY;
    foreach(Interface* intf, this->_typeOfDevice->GetInterfaces())
    {
        painter->drawEllipse(_startX+40,currentY-30,10,10);
        currentY+=20;
    }
    painter->drawText(_startX,_startY, this->_typeOfDevice->GetName());
}*/

