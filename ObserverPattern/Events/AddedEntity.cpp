//
// Created by laurens on 12/3/17.
//

#include "AddedEntity.h"

OP::Event::AddedEntity::AddedEntity() {}

OP::Event::AddedEntity::AddedEntity(const std::shared_ptr<OP::Subject> &entity) : entity(entity) {}

const std::shared_ptr<OP::Subject> OP::Event::AddedEntity::getEntity() const {
    return entity;
}
