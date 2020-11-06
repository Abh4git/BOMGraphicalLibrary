#ifndef INTERFACE_H
#define INTERFACE_H
#include <QString>
namespace WSIM
{
enum Type
{
    Storage,
    Commmunication,
    OperatingSystem,
    Processor,
    Field,
	IEC61850LNClass,
	ProcessObjectClass

};
class Interface
{

public:



    Interface(int id, QString name, Type typeEnumVal,bool external=false)
    {
        _typeOfInterface=typeEnumVal;
        _id=id;
        _name=name  ;
        if(typeEnumVal==WSIM::Commmunication ||typeEnumVal==WSIM::Field)  external=true;
        _externalInterface=external;
    }

    int GetId()
    {
        return _id;
    }
    QString GetName()
    {
        return _name;
    }
    bool GetExternal()
    {
        return _externalInterface;
    }

    enum EndianNess
    {
        litte=1,
        Big=2
    };
	Type getTypeOfInterface()
	{
		return _typeOfInterface;
	}
private:
    Type _typeOfInterface;
    int _id;
    QString _name;
    bool _externalInterface;
};
}
#endif // INTERFACE_H
