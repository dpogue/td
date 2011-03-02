#include "ResManager.h"
#include "Player.h"
#include "Projectile.h"

namespace td {

ResManager::ResManager() {
    objects_ = QVector<QList<GameObject*> >(clsidx::kMAX_CLASS_INDEX);
}

ResManager::~ResManager() {
    objects_.clear();
}

GameObject* ResManager::createObject(unsigned char type) {
    GameObject* ret = NULL;
    unsigned int id = 0;

    switch (type) {
        case clsidx::kPlayer:
            ret = new Player();
            id = (Player::clsIdx() << 24) | objects_[type].size();
            ret->setID(id);
            break;
        case clsidx::kProjectile:
            ret = new Projectile();
            id = (Projectile::clsIdx() << 24) | objects_[type].size();
            ret->setID(id);
            break;
        case clsidx::kGameObject:
        case clsidx::kUnit:
        default:
            break;
    }

    objects_[type].append(ret);

    return ret;
}

void ResManager::addExistingObject(GameObject* obj, unsigned char type, unsigned int id) {

    objects_[type].insert((id & 0x00FFFFFF), obj);

}


GameObject* ResManager::findObject(unsigned int id) {
    unsigned char type = (id & 0xFF000000) >> 24;
    unsigned int objid = (id & 0x00FFFFFF);

    if (type >= clsidx::kMAX_CLASS_INDEX
            || objid >= objects_[type].size())
    {
        return NULL;
    }

    return objects_[type][objid];
}

void ResManager::deleteObject(unsigned int id) {
    unsigned char type = (id & 0xFF000000) >> 24;
    unsigned int objid = (id & 0x00FFFFFF);

    GameObject* obj = findObject(id);

    if (obj != NULL) {
        objects_[type].removeAt(objid);
        delete obj;
        obj = NULL;
    }
}

void ResManager::deleteObject(GameObject* obj) {
    deleteObject(obj->getID());

    obj = NULL;
}

unsigned int ResManager::countObjects() const {
    unsigned int count = 0;

    for (int i = 0; i < clsidx::kMAX_CLASS_INDEX; i++) {
        count += objects_[i].size();
    }

    return count;
}

} /* end namespace td */
