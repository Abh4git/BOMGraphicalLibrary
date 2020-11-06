#include <bominstance.h>

#ifndef BOMEQPTPRIMINSTANCE_H
#define BOMEQPTPRIMINSTANCE_H
using namespace BOMLIB;
using namespace WSIMINST;

//! BOMIEquipment
	/*!
		Responsibility: A BOM Instance specifically to create an Equipment like Boiler
		The constructor has specific approach of Graphical creation. The BOMInstance is created
		from bomfactory.cpp
	*/
class BOMIEquipment: virtual public BOMInstance
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
	BOMIEquipment(BOMObject* bomType, int centerX,int centerY,int instanceNumber, QString userDefName="");
	~BOMIEquipment();
	//! GetContainedBOMType
	/*!
		Return the BOMType associated with the BOM Instance
	*/
	BOMObject* GetContainedBOMType();
	//! GetInstanceNumber
	/*!
		Return the Instance number for the instance
	*/
	int GetInstanceNumber();
};
#endif //BOMEQPTPRIMINSTANCE_H