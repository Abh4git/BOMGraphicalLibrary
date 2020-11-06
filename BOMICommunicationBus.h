#include <bominstance.h>
using namespace BOMLIB;
using namespace WSIMINST;


#pragma once
	//! BOMICommunicationBus
	/*!
		Responsibility: A BOM Instance specifically to create a Communication Bus instance
		The constructor has specific approach of Graphical creation. The BOMInstance is created
		from bomfactory.cpp
	*/
class BOMICommunicationBus: virtual public BOMInstance
{
public:
	//! Constructor
	/*!
		\param bomType type of BOMObject to be instantiated
		\param centerX x pos of Graphical instance center
		\param centerY y pos of Graphical instance center
		\param instanceNumber to be instantiated BOM Object
		\param userDefName string for userdefined name
		The constructor has specific approach of Graphical creation. The BOMInstance is created
		from bomfactory.cpp
	*/
	BOMICommunicationBus(BOMObject* bomType, int centerX,int centerY,int instanceNumber, QString userDefName="");
	//Destructor
	~BOMICommunicationBus(void);
};

