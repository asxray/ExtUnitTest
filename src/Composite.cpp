/*
 * Composite.cpp
 *
 *  Created on: Apr 22, 2014
 *      Author: josephx
 */

#include "Composite.hpp"

namespace dp {
Component::Component() : parent(nullptr) {}

Component::~Component() {}

const std::string& Component::getName() const { return (name); }

void Component::setName(const std::string& name) { this->name = name; }

Component const* Component::getParent() const { return (parent); }

void Component::setParent(Component const* const parent) {
  assert(parent);
  this->parent = parent;
}

const std::string Component::getFullname() const {
  if (parent)
    return (parent->getFullname() + "/" + this->name);
  else
    return (this->name);
}

Composite::~Composite() {}

void Composite::Add(spComponent child) {
  assert(child.get() != this);
  child->setParent(this);
  children.push_back(child);
}
void Composite::Clear(void) { children.clear(); }
}  // namespace
