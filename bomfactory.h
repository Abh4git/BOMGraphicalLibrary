#ifndef BOMGRAPHFACTORY_H
#define BOMGRAPHFACTORY_H


//#include <qplugin.h>
#include <IBOMInstanceCreation.h>
#include <connectorbase.h>
#include <connectorgraphicitem.h>
#include <BOMFactory_global.h>
#include <ActionGraphicsItem.h>
#include <steamGraphicsItemWithText.h>
#include <signalGraphicsItemWithText.h>
#include <QtPlugin>
#include <QMetaType>
//Q_IMPORT_PLUGIN(qjpeg)
//Q_IMPORT_PLUGIN(qgif)
//Q_IMPORT_PLUGIN(qico)

using namespace BOMLIB;
using namespace WSIMINST;
	//! BOMFactory
	/*!
		Responsibility : Creation of Instances of BOM Object Types
		For example Say for BOM Object Boiler, we create instance
		Boiler instance 1 and BOM Object Controller, we create
		Controller instance 1 and interconnect them.
		Implements IBOMInstanceCreation class
	*/
class BOMFACTORY_EXPORT BOMFactory : public QObject, public IBOMInstanceCreation
{
	Q_OBJECT

    Q_PLUGIN_METADATA(IID "graphics.bom.library")
    Q_INTERFACES(IBOMInstanceCreation)

public:

	//! Constructor
	BOMFactory(QObject *parent=0)
	{

	}
	//!Destructor
	~BOMFactory()
	{

	}
/*private:
    BOMFactory()
    {
    }*/

public:

	//! createBOMInstance
	/*!
		\param typeofBOM a BOM Object Type
		\param centerPointX x value of center of object
		\param centerPointY y value of center of object
		\param UserDefName String value of user defined name
		Returns a BOMInstance once instantiated on GraphicsScene
	*/ 	//factory method
	BOMInstance* createBOMInstance(BOMObject* typeofBOM,int centerPointX,int centerPointY, QString UserDefName="Default");
	//! createConnector
	/*!
		\param startX a start X value
		\param startY a start Y value
		\param endX an end X value
		\param endY an end Y value
		Returns a ConnectorGraphicitem once instantiated on GraphicsScene
	*/ 	
	ConnectorGraphicitem* createConnector(int startX,int startY, int endX,int endY, QString UserDefName="Default");
	//! createMessagePacketTxt
	/*!
		\param position a QPosition on scene
		\param UserDefname String value of user defined name
		Returns a msgGraphicsItemWithText once instantiated on GraphicsScene
	*/ 	
	msgGraphicsItemWithText* createMessagePacketTxt(QPoint position,QString UserDefname="Packet");
	//! createMessagePacket
	/*!
		\param position a QPosition on scene
		Returns a MsgGraphicsItem once instantiated on GraphicsScene
	*/ 	
	MsgGraphicsItem* createMessagePacket(QPoint position);
	//! createActionSignal
	/*!
		\param position a QPosition on scene
		Returns a ActionGraphicsItem once instantiated on GraphicsScene
	*/ 	
	ActionGraphicsItem* createActionSignal(QPoint position);
    //! createSignal
    /*!
        \param position a QPosition on scene
        Returns a signalGraphicsItemWithText once instantiated on GraphicsScene
    */
    signalGraphicsItemWithText* createSignalWithText(QPoint position,QString UserDefName="Signal");
    //! createHeatSteamTransfer
    /*!
        \param position a QPosition on scene
        Returns a steamGraphicsItemWithText once instantiated on GraphicsScene
    */
    steamGraphicsItemWithText* createHeatSteamTransferWithText(QPoint position,QString UserDefName="Signal");
    //! createGenericGraphicItemWithText
    /*!
        \param position a QPosition on scene
        Returns a genericGraphicsItemWithText once instantiated on GraphicsScene
    */
    genericGraphicsItemWithText* createGenericGraphicItemWithText(QPoint position,QString UserDefName="",QString iconName="");

    //! createHighLightedText
	/*!
		\param position a QPosition on scene
		\param valueText a string on scene
		Returns a QGraphicsTextItem once instantiated on GraphicsScene
	*/ 	
	QGraphicsTextItem* createHighLightedText(QPoint position,QString valueText);
private:
	
};

#endif // BOMGRAPHFACTORY_H

