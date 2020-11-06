#include <bominstance.h>
#ifndef BOMELECTPRIMINSTANCE_H
#define BOMELECTPRIMINSTANCE_H
using namespace BOMLIB;
using namespace WSIMINST;
//! BOMIElectricPrimary
	/*!
		Responsibility: A BOM Instance specifically to create an Electrical or Process Device
		The constructor has specific approach of Graphical creation. The BOMInstance is created
		from bomfactory.cpp
	*/
class BOMIElectricPrimary: virtual public BOMInstance
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
	BOMIElectricPrimary(BOMObject* bomType, int centerX,int centerY,int instanceNumber, QString userDefName="");
	~BOMIElectricPrimary();
	//! GetContainedBOMType
	/*!
		Return the BOMType associated with the BOM Instance
	*/
	BOMObject* GetContainedBOMType();
	//! GetInstanceNumber
	/*!
		Return the Instance Number for the BOM Instance
	*/
	int GetInstanceNumber();
};
#endif //BOMELECTPRIMINSTANCE_H