#ifndef GENERICGRAPHICSITEMWITHTEXT_H
#define GENERICGRAPHICSITEMWITHTEXT_H



#include <QGraphicsItemGroup>
#include <qpoint.h>
//! genericGraphicsItemWithText
    /*!
        Responsibility: To create a Communication Message as Item in scene
        with a Text in addition
    */
class genericGraphicsItemWithText : public QObject, public QGraphicsItemGroup
{
    Q_OBJECT
    Q_PROPERTY(QPointF pos READ pos WRITE setPos)
public:
    //! Constructor
    /*!
        \param position as QPoint
        \param UserDefName as string
    */
    genericGraphicsItemWithText(QPoint position,QString UserDefName,QString iconName);
    ~genericGraphicsItemWithText(void);
};



#endif // GENERICGRAPHICSITEMWITHTEXT_H
