#include "connectorgraphicitem.h"

using namespace WSIMINST;

ConnectorGraphicitem::ConnectorGraphicitem(QString identifier,ConnectorBase *typeofConnect, QGraphicsItem *parent, QPointF sourcePt, QPointF destPt)
{

	m_sourcePt=sourcePt;
	m_destPt=destPt;
	m_identifier=identifier;
    QPen pen(Qt::blue, 2);
    setPen(pen);
    QPainterPath path;
    //if vertical or horizontal then draw straight line
    if (sourcePt.x()==destPt.x() || sourcePt.y()==destPt.y())
    {
        path.moveTo(sourcePt.x(),sourcePt.y());
        path.lineTo(destPt.x(),destPt.y());
    } else //break into two lines - 1 horizontal and other vertical (instead of diagonal)
    {
        int halfdist= destPt.x() - sourcePt.x();
        //now draw first straight line till half dist horizontal
        path.moveTo(sourcePt.x(),sourcePt.y());
        path.lineTo(halfdist+9,sourcePt.y());
        //now draw first straight line till half dist horizontal
        path.lineTo(destPt.x(),destPt.y());

    }
	setPath(path);
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
	setData(1,"message");
}

ConnectorGraphicitem::ConnectorGraphicitem( QGraphicsItem *parent, QPointF sourcePt, QPointF destPt)
{

    QPen pen(Qt::blue, 2);
    setPen(pen);
    QPainterPath path;
    this->m_destPt=destPt;
    this->m_sourcePt=sourcePt;
    //if vertical or horizontal then draw straight line
    if (sourcePt.x()==destPt.x() || sourcePt.y()==destPt.y())
    {
        path.moveTo(sourcePt.x(),sourcePt.y());
        path.lineTo(destPt.x(),destPt.y());
    } else //break into two lines - 1 horizontal and other vertical (instead of diagonal)
    {
        int halfdist= destPt.x() - sourcePt.x();
        //now draw first straight line till half dist horizontal
        path.moveTo(sourcePt.x(),sourcePt.y());
        path.lineTo(halfdist+9,sourcePt.y());
        //now draw first straight line till half dist horizontal
        path.lineTo(destPt.x(),destPt.y());

    }
    setPath(path);
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);

}
