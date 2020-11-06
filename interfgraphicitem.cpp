#include "interfgraphicitem.h"

using namespace WSIMINST;
InterfGraphicItem::InterfGraphicItem(QGraphicsItem *parent)
{
    setRect(10,10,20,20);
}

InterfGraphicItem::InterfGraphicItem(Interface *typeOfInterface, QGraphicsItem *parent, int startX, int startY):QGraphicsEllipseItem(parent)
{
    QPen pen(Qt::blue, 2);
    _startX=startX;
    _startY=startY;
    setPen(pen);
    QBrush brush(Qt::green);
    setBrush(brush);
    setRect(QRectF(startX,startY, 10, 10));
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);

}
