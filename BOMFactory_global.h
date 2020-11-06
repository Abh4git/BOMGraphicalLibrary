#ifndef BOMFACTORY_GLOBAL_H
#define BOMFACTORY_GLOBAL_H

#include <QtCore/qglobal.h>

#ifdef BOMFACTORY_LIB
# define BOMFACTORY_EXPORT Q_DECL_EXPORT
#else
# define BOMFACTORY_EXPORT Q_DECL_IMPORT
#endif



#endif // BOMFACTORY_GLOBAL_H

//
