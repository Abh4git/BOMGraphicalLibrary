# ----------------------------------------------------
# This file is generated by the Qt Visual Studio Add-in.
# ------------------------------------------------------

TEMPLATE = lib
TARGET = BOMGraphicalLibrary
DESTDIR = ./Win32/Release
QT += core gui widgets xml designer
CONFIG += release
DEFINES += QT_LARGEFILE_SUPPORT QT_DLL QT_XML_LIB
#QT_STATICPLUGIN
DEFINES += BOMFACTORY_LIB
INCLUDEPATH += ./GeneratedFiles \
    . \
    ./GeneratedFiles/release
LIBS += C:\Abhilash\MyToolBox\OpenSourceBranch\ScenarioEditor\Output\libBOMLibrary.a
DEPENDPATH += .
MOC_DIR += ./GeneratedFiles/release
OBJECTS_DIR += release
UI_DIR += ./GeneratedFiles
#RCC_DIR += ./GeneratedFiles
RESOURCES += bomelements.qrc
include(BOMGraphicalLibrary.pri)

