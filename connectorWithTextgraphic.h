#ifndef CONNWITHTXTGRAPH_H
#define CONNWITHTXTGRAPH_H
#include <QGraphicsItemGroup>
//not in use now
//! ConnectorGraphicitem class
	/*!
		Responsibility: Create Connectors in Graphics Scene with added Text based on source and destination points
	*/
class connectorWithTextgraphic:public QGraphicsItemGroup
{
public:
	connectorWithTextgraphic(void);
	~connectorWithTextgraphic(void);
};

#endif