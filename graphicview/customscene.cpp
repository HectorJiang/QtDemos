#include "customscene.h"
#include <QDebug>
#include <QGraphicsSceneDragDropEvent>
#include <QMimeData>
#include <QListWidget>
#include <QGraphicsPixmapItem>
CustomScene::CustomScene()
{

}
void CustomScene::dragEnterEvent(QGraphicsSceneDragDropEvent *)
{
    qDebug() << __FUNCTION__;
}

void CustomScene::dragLeaveEvent(QGraphicsSceneDragDropEvent *)
{
    qDebug() << __FUNCTION__;
}

void CustomScene::dragMoveEvent(QGraphicsSceneDragDropEvent *)
{
    qDebug() << __FUNCTION__;
}

void CustomScene::dropEvent(QGraphicsSceneDragDropEvent *pEvent){
    qDebug()<<__FUNCTION__;
    if (pEvent->mimeData()->hasFormat("application/x-qabstractitemmodeldatalist"))
    {
        QListWidget *pListwidget = qobject_cast<QListWidget *>(pEvent->source());

        QString strPixmapPath = ":/" + pListwidget->currentItem()->text() + ".png";
        QPixmap p(strPixmapPath);
        QGraphicsPixmapItem *pPixmapItem = new QGraphicsPixmapItem(p);

//        pPixmapItem->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
        pPixmapItem->setFlag(QGraphicsItem::ItemIsMovable);
        pPixmapItem->setFlag(QGraphicsItem::ItemIsSelectable);
        pPixmapItem->setPos(pEvent->scenePos());

        addItem(pPixmapItem);
    }
}
