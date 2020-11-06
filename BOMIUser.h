#pragma once
#include "bominstance.h"
using namespace BOMLIB;
using namespace WSIMINST;
	//! BOMIEquipment
	/*!
		Responsibility: A BOM Instance specifically to create an q User/Actor object
		The constructor has specific approach of Graphical creation. The BOMInstance is created
		from bomfactory.cpp
	*/
class BOMIUser :
	virtual public BOMInstance
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
	BOMIUser(BOMObject* bomType, int centerX,int centerY,int instanceNumber, QString userDefName="");
	~BOMIUser(void);
};

