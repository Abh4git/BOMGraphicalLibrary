#ifndef STEAMGRAPHICSITEMWITHTEXT_H
#define STEAMGRAPHICSITEMWITHTEXT_H

#include <QGraphicsItemGroup>
#include <qpoint.h>
//! steamGraphicsItemWithText
    /*!
        Responsibility: To create a Steam/Heat Transfer as Item in scene
        with a Text in addition
    */
class steamGraphicsItemWithText : public QObject, public QGraphicsItemGroup
{
    Q_OBJECT
    Q_PROPERTY(QPointF pos READ pos WRITE setPos)
public:
    //! Constructor
    /*!
        \param position as QPoint
        \param UserDefName as string
    */
    steamGraphicsItemWithText(QPoint position,QString UserDefName);
    ~steamGraphicsItemWithText(void);
};


#endif // STEAMGRAPHICSITEMWITHTEXT_H
