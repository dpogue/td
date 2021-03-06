#ifndef TD_NPCGRAPHICSCOMPONENTTYPES_H
#define TD_NPCGRAPHICSCOMPONENTTYPES_H

#include "NPCGraphicsComponent.h"

namespace td {

class NormNPCGraphicsComponent : public NPCGraphicsComponent
{
    Q_OBJECT

private:
    /** The array of pixmaps for the animations. */
    static QPixmap* pixmapImgs_;

public:
    NormNPCGraphicsComponent() : NPCGraphicsComponent() {
        emit created(this);
    }
    virtual ~NormNPCGraphicsComponent() { }

    /**
     * Initializes the static array of pixmaps.
     *
     * @author Warren Voelkl
     */
    virtual void initPixmaps();

    /**
     * Returns the array of pixmap images.
     *
     * @author Warren Voelkl
     * @return The list of static pixmaps used for animations.
     */
    virtual QPixmap* getPixmapArray() {
        return pixmapImgs_;
    }

private:
    virtual void setNonStaticValues();
    virtual void setLayer(void* dp);
};

class SlowNPCGraphicsComponent : public NPCGraphicsComponent
{
    Q_OBJECT

private:
    /** The array of pixmaps for the animations. */
    static QPixmap* pixmapImgs_;

public:
    SlowNPCGraphicsComponent() : NPCGraphicsComponent() {
        emit created(this);
    }
    virtual ~SlowNPCGraphicsComponent() { }

    /**
     * Initializes the static array of pixmaps.
     *
     * @author Warren Voelkl
     */
    virtual void initPixmaps();

    /**
     * Returns the array of pixmap images.
     *
     * @author Warren Voelkl
     * @return The list of static pixmaps used for animations.
     */
    virtual QPixmap* getPixmapArray() {
        return pixmapImgs_;
    }

private:
    virtual void setNonStaticValues();
    virtual void setLayer(void* dp);
};

class ArmNPCGraphicsComponent : public NPCGraphicsComponent
{
    Q_OBJECT

private:
    /** The array of pixmaps for the animations. */
    static QPixmap* pixmapImgs_;

public:
    ArmNPCGraphicsComponent() : NPCGraphicsComponent() {
        emit created(this);
    }
    virtual ~ArmNPCGraphicsComponent() { }

    /**
     * Initializes the static array of pixmaps.
     *
     * @author Warren Voelkl
     */
    virtual void initPixmaps();

    /**
     * Returns the array of pixmap images.
     *
     * @author Warren Voelkl
     * @return The list of static pixmaps used for animations.
     */
    virtual QPixmap* getPixmapArray() {
        return pixmapImgs_;
    }

private:
    virtual void setNonStaticValues();
    virtual void setLayer(void* dp);
};

class FastNPCGraphicsComponent : public NPCGraphicsComponent
{
    Q_OBJECT

private:
    /** The array of pixmaps for the animations. */
    static QPixmap* pixmapImgs_;

public:
    FastNPCGraphicsComponent() : NPCGraphicsComponent() {
        emit created(this);
    }
    virtual ~FastNPCGraphicsComponent() { }

    /**
     * Initializes the static array of pixmaps.
     *
     * @author Warren Voelkl
     */
    virtual void initPixmaps();

    /**
     * Returns the array of pixmap images.
     *
     * @author Warren Voelkl
     * @return The list of static pixmaps used for animations.
     */
    virtual QPixmap* getPixmapArray() {
        return pixmapImgs_;
    }

private:
    virtual void setNonStaticValues();
    virtual void setLayer(void* dp);
};

class SwarmNPCGraphicsComponent : public NPCGraphicsComponent
{
    Q_OBJECT

private:
    /** The array of pixmaps for the animations. */
    static QPixmap* pixmapImgs_;

public:
    SwarmNPCGraphicsComponent() : NPCGraphicsComponent() {
        emit created(this);
    }
    virtual ~SwarmNPCGraphicsComponent() { }

    /**
     * Initializes the static array of pixmaps.
     *
     * @author Warren Voelkl
     */
    virtual void initPixmaps();

    /**
     * Returns the array of pixmap images.
     *
     * @author Warren Voelkl
     * @return The list of static pixmaps used for animations.
     */
    virtual QPixmap* getPixmapArray() {
        return pixmapImgs_;
    }

private:
    virtual void setNonStaticValues();
    virtual void setLayer(void* dp);
};

class FlyNPCGraphicsComponent : public NPCGraphicsComponent
{
    Q_OBJECT

private:
    /** The array of pixmaps for the animations. */
    static QPixmap* pixmapImgs_;

public:
    FlyNPCGraphicsComponent() : NPCGraphicsComponent() {
        emit created(this);
    }
    virtual ~FlyNPCGraphicsComponent() { }

    /**
     * Initializes the static array of pixmaps.
     *
     * @author Warren Voelkl
     */
    virtual void initPixmaps();

    /**
     * Returns the array of pixmap images.
     *
     * @author Warren Voelkl
     * @return The list of static pixmaps used for animations.
     */
    virtual QPixmap* getPixmapArray() {
        return pixmapImgs_;
    }

private:
    virtual void setNonStaticValues();
    virtual void setLayer(void* dp);
};

class BossNPCGraphicsComponent : public NPCGraphicsComponent
{
    Q_OBJECT

private:
    /** The array of pixmaps for the animations. */
    static QPixmap* pixmapImgs_;

public:
    BossNPCGraphicsComponent() : NPCGraphicsComponent() {
        emit created(this);
    }
    virtual ~BossNPCGraphicsComponent() { }

    /**
     * Initializes the static array of pixmaps.
     *
     * @author Warren Voelkl
     */
    virtual void initPixmaps();

    /**
     * Returns the array of pixmap images.
     *
     * @author Warren Voelkl
     * @return The list of static pixmaps used for animations.
     */
    virtual QPixmap* getPixmapArray() {
        return pixmapImgs_;
    }

private:
    virtual void setNonStaticValues();
    virtual void setLayer(void* dp);
};

} /* end namespace td */

#endif
