/*
 * Composite.hpp
 *
 *  Created on: Apr 14, 2014
 *      Author: josephx
 */

#ifndef COMPOSITE_HPP_
#define COMPOSITE_HPP_

#include "Visitor.hpp"
#include <boost/ptr_container/ptr_list.hpp>
#include <string>

namespace eutest
{
class Component
    : virtual public BaseVisitable<>
{
public:
    VISITABLE();
    Component() {}
    virtual
    ~Component() {}
    const std::string&
    getName() const
    {
        return(name);
    }
    void
    setName(const std::string& name)
    {
        this->name = name;
    }
    Component*&
    getParent()
    {
        return(parent);
    }
    void
    setParent(Component* parent)
    {
        this->parent = parent;
    }
protected:
    std::string name;
    Component*  parent;
};
template<class T>
class Leaf
    : virtual public Component,
      virtual public BaseVisitable<>
{
public:
    Leaf() {}
    virtual
    ~Leaf() {}
    virtual void
    Accept(eutest::BaseVisitor& guest)
    {
        AcceptImpl(*dynamic_cast<T*>(this), guest);
    }
};
template<class T>
class Composite
    : virtual public Component,
      virtual public BaseVisitable<>
{
protected:
    typedef boost::ptr_list<Component> Container;
public:
    Composite()
    {}
    virtual
    ~Composite() {}
    virtual void
    Accept(eutest::BaseVisitor& guest)
    {
        AcceptImpl(*dynamic_cast<T*>(this), guest);
        for (Container::iterator i = children.begin();
             children.end() != i;
             ++i)
            i->Accept(guest);
    }
    void
    Add(Component* aChild)
    {
        aChild->setParent(dynamic_cast<T*>(this));
#pragma omp critical
        children.push_back(aChild);
    }
    void
    Clear(void)
    {
#pragma omp critical
        children.clear();
    }

protected:
    Container children;
};
} /* namespace eutest */

#endif /* COMPOSITE_HPP_ */
