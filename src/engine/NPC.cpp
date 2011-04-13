#include "NPC.h"
#include "NPCWave.h"
#include "Driver.h"
#include <QObject>
#include "../audio/SfxManager.h"

#ifndef SERVER
#    include "CDriver.h"
#endif

namespace td {

NPC::NPC(QObject* parent) : Unit(parent), damage_(5), wave_(NULL) {
    QVector2D force(0, 0);
    this->setForce(force);
    this->setVelocity(force);
    this->setHeight(90);
    this->setWidth(30);
    pos_.setX(50);
    pos_.setY(50);

    connect(this, SIGNAL(dead(int)),
            parent, SLOT(destroyObject(int)), Qt::QueuedConnection);
}

NPC::~NPC() {
    if (wave_ != NULL) {
        wave_->killChild(this);
    }
    emit signalNPCDied();
}

int NPC::getHealth() {
    return health_;
}

void NPC::setHealth(int health){
    health_ = health;
    setDirty(kHealth);
#ifndef SERVER
    ((NPCGraphicsComponent*) graphics_)->showDamage();
#endif
}

int NPC::getDamage() {
    return damage_;
}

void NPC::setDamage(int damage) {
    damage_ = damage;
}

int NPC::getMaxHealth() {
    return maxHealth_;
}

void NPC::setMaxHealth(int maxHealth) {
    maxHealth_ = maxHealth;
}

void NPC::networkRead(Stream* s) {
    Unit::networkRead(s);

    if (dirty_ & kType) {
        type_ = s->readInt();
    }

    if (dirty_ & kHealth) {
        health_ = s->readInt();
#ifndef SERVER
        if (graphics_ != NULL) {
            ((NPCGraphicsComponent*) graphics_)->showDamage();
        }
#endif
    }
}

void NPC::networkWrite(Stream* s) {
    Unit::networkWrite(s);

    if (dirty_ & kType) {
        s->writeInt(type_);
    }

    if (dirty_ & kHealth) {
        s->writeInt(health_);
    }
}

QVector2D NPC::getRandomVector() {
    float d = ((qrand() % 1000) / 21.0) + 50;
    float direction = (qrand() % 1000) - 500;
    QLineF normalVector = QLineF(QPointF(0, 0), velocity_.toPointF());

    normalVector = normalVector.normalVector();

    QVector2D v = QVector2D(normalVector.p2()) * direction;
    v.normalize();

    return (v * d);
}

void NPC::initComponents() {
    NPCInputComponent* input;

    switch(type_) {
        case NPC_NORM:
            maxHealth_ = health_ = 100;
            input = new NormNPCInputComponent();
            input->setParent(this);
            setPhysicsComponent(new NormNPCPhysicsComponent());
#ifndef SERVER
            setGraphicsComponent(new NormNPCGraphicsComponent());
#endif
            setInputComponent(input);
            break;
        case NPC_SLOW:
            maxHealth_ = health_ = 200;
            input = new SlowNPCInputComponent();
            input->setParent(this);
            setPhysicsComponent(new SlowNPCPhysicsComponent());
#ifndef SERVER
            setGraphicsComponent(new SlowNPCGraphicsComponent());
#endif
            setInputComponent(input);
            break;
        case NPC_FAST:
            maxHealth_ = health_ = 50;
            input = new FastNPCInputComponent();
            input->setParent(this);
            setPhysicsComponent(new FastNPCPhysicsComponent());
#ifndef SERVER
            setGraphicsComponent(new FastNPCGraphicsComponent());
#endif
            setInputComponent(input);
            break;
        case NPC_FLY:
            maxHealth_ = health_ = 100;
            input = new FlyNPCInputComponent();
            input->setParent(this);
            setPhysicsComponent(new FlyNPCPhysicsComponent());
#ifndef SERVER
            setGraphicsComponent(new FlyNPCGraphicsComponent());
#endif
            setInputComponent(input);
            break;
        case NPC_BOSS:
            maxHealth_ = health_ = 300;
            input = new BossNPCInputComponent();
            input->setParent(this);
            setPhysicsComponent(new BossNPCPhysicsComponent());
#ifndef SERVER
            setGraphicsComponent(new BossNPCGraphicsComponent());
#endif
            setInputComponent(input);
            break;
    }

#ifndef SERVER
    if (!((CDriver*)getDriver())->isSinglePlayer()) {
        delete getInputComponent();
        delete getPhysicsComponent();
        setInputComponent(NULL);
        setPhysicsComponent(NULL);
    }
#endif
}

void NPC::createEffect(Effect* effect){
    if (effects_.contains(*effect)) {
        emit stopEffect(effect->getType());
        effects_.removeOne(*effect);
    }
    QObject::connect(effect, SIGNAL(effectFinished(Effect*)),
        this, SLOT(deleteEffect(Effect*)));
    connect(this, SIGNAL(stopEffect(uint)),
        effect, SLOT(effectStop(uint)));
    connect(getDriver()->getTimer(), SIGNAL(timeout()),
        effect, SLOT(update()));
        
    effects_.push_back(*effect);

    switch (effect->getType()) {
    case EFFECT_ARROW:
	    PLAY_SFX(this, SfxManager::projectileHitArrow);
        break;
    case EFFECT_CANNON:
	    PLAY_SFX(this, SfxManager::projectileHitCannon);
        break;
    case EFFECT_TAR:
	    PLAY_SFX(this, SfxManager::projectileHitTar);
        break;
    case EFFECT_FLAK:
	    PLAY_SFX(this, SfxManager::projectileHitFlak);
        break;
    }
}

void NPC::deleteEffect(Effect* effect){
    effects_.removeOne(*effect);
    delete effect;
    if (effects_.empty()) {
        // TODO: connect to a slot in projectile collisions for sfx
        //emit signalEmptyEffectList();
    }
}

void NPC::isDead() {
    if(health_ <= 0) {
        //TODO NPC death sound/animation
        emit signalDropResource(RESOURCE_GEM, pos_, getRandomVector());
        emit dead(this->getID());
    }
}

void NPC::update() {
    if (input_ != NULL) {
        input_->update();
    }
    if (physics_ != NULL) {
        physics_->update(this);
    }

    /*if (isDirty()) {
        getDriver()->updateRT(this);
    }*/

    if (graphics_ != NULL) {
        graphics_->update(this);
    }

    this->isDead();
}

} /* end namespace td */
