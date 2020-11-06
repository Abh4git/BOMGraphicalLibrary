#ifndef BOMISECOND_H
#define BOMISECOND_H
#pragma once
#include <bominstance.h>
using namespace BOMLIB;
using namespace WSIMINST;

class BOMISecondary: virtual public BOMInstance
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
	BOMISecondary(BOMObject* bomType, int centerX,int centerY,int instanceNumber, QString userDefName="");
	~BOMISecondary();
};
#endif
