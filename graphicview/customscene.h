#ifndef CUSTOMSCENE_H
#define CUSTOMSCENE_H
#include <QGraphicsScene>

class CustomScene : public QGraphicsScene
{
public:
    CustomScene();
protected:
    void dragEnterEvent(QGraphicsSceneDragDropEvent *) Q_DECL_OVERRIDE;
    void dragLeaveEvent(QGraphicsSceneDragDropEvent *) Q_DECL_OVERRIDE;
    void dragMoveEvent(QGraphicsSceneDragDropEvent *) Q_DECL_OVERRIDE;
    void dropEvent(QGraphicsSceneDragDropEvent *) Q_DECL_OVERRIDE;

};

#endif // CUSTOMSCENE_H
