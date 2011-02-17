#include "ContextMenuGraphicsComponent.h"
#include "Player.h"

ContextMenuGraphicsComponent::ContextMenuGraphicsComponent()
        : GraphicsComponent() {
}

void ContextMenuGraphicsComponent::update(GameObject* obj) {
    Player* player = (Player*)obj;
    QGraphicsPixmapItem* itm = getPixmapItem();

    if (itm != NULL) {
        DRAWSTRUCT* pds = (DRAWSTRUCT*) malloc(sizeof(DRAWSTRUCT));

        pds->pos     = player->getPos();
        pds->moving  = player->getVelocity().length() != 0;
        //pds->scale   = player->getScale();
        pds->scale   = 1;
        //pds->degrees = player->getOrientation();
        pds->degrees = 90;
        
        emit signalDraw(pds, this);
    }
}

