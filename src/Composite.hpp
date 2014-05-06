/*
 * Composite.hpp
 *
 *  Created on: Apr 14, 2014
 *      Author: josephx
 */

#ifndef COMPOSITE_HPP_
#define COMPOSITE_HPP_

#include "Visitor.hpp"
#include <list>
#include <memory>
#include <string>

namespace dp {
class Component : public BaseVisitable<> {
 protected:
  typedef std::shared_ptr<Component> spComponent;
  Component const* parent;
  std::string name;

 public:
  Component();
  virtual ~Component();
  const std::string& getName() const;
  void setName(const std::string& name);
  Component const* getParent() const;
  void setParent(Component const* const parent);
  const std::string getFullname() const;
};

class Composite : public Component {
 protected:
  std::list<spComponent> children;

 public:
  virtual ~Composite();
  void Add(spComponent child);
  void Clear(void);

 protected:
  template <class T>
  void Traverse(T* const visited, BaseVisitor* const guest) const {
    AcceptImpl(visited, guest);
    for (auto& i : children) i->Accept(guest);
  }
};
#define VISITABLECOMPOSITE()                          \
  virtual void Accept(dp::BaseVisitor* const guest) { \
    return Traverse(this, guest);                     \
  }
} /* namespace eutest */

#endif /* COMPOSITE_HPP_ */
