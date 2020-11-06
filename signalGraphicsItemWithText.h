#ifndef SIGNALGRAPHICSITEMWITHTEXT_H
#define SIGNALGRAPHICSITEMWITHTEXT_H


#include <QGraphicsItemGroup>
#include <qpoint.h>
//! signalGraphicsItemWithText
    /*!
        Responsibility: To create a Communication Message as Item in scene
        with a Text in addition
    */
class signalGraphicsItemWithText : public QObject, public QGraphicsItemGroup
{
    Q_OBJECT
    Q_PROPERTY(QPointF pos READ pos WRITE setPos)
public:
    //! Constructor
    /*!
        \param position as QPoint
        \param UserDefName as string
    */
    signalGraphicsItemWithText(QPoint position,QString UserDefName);
    ~signalGraphicsItemWithText(void);
};


#endif // SIGNALGRAPHICSITEMWITHTEXT_H
