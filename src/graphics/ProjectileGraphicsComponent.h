#ifndef PROJECTILEGRAPHICSCOMPONENT_H
#define PROJECTILEGRAPHICSCOMPONENT_H

#include <QObject>
#include <QPainter>
#include <QPointF>
#include "GraphicsComponent.h"

class ProjectileGraphicsComponent : public GraphicsComponent {
    Q_OBJECT

public:
    /**
     * Instantiates a projectile graphics component
     * @author Warren Voelkl
     */
    ProjectileGraphicsComponent();
    virtual ~ProjectileGraphicsComponent();

    /**
     * Loads a structure from the item and game component class then sends
     * the structure to the generic draw slot in GraphicsComponent.
     *
     * @author Warren Voelkl
     */
    virtual void update(GameObject* obj);

    /**
     * Gets a pixmap for the object based on its current animation state.
     *
     * @author Warren Voelkl
     */
    virtual void initPixmaps();
};

#endif

