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
    : public BaseVisitable<>
{
protected:
    std::string      name;
    Component const* parent;
public:
    Component()
        : parent(0) {}
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
    Component const* const
    getParent() const
    {
        return(parent);
    }
    void
    setParent(Component const* const parent)
    {
        this->parent = parent;
    }
};
template<class T>
class Leaf
    : public Component
{
    virtual void
    Accept(BaseVisitor& guest)
    {
        if (T * p = dynamic_cast<T*>(this))
            AcceptImpl(*p, guest);
        else
            assert(0);
    }
};

template<class T>
class Composite
    : public Component
{
protected:
    typedef boost::ptr_list<Component> Container;
    Container children;
public:
    virtual void
    Accept(BaseVisitor& guest)
    {
        if (T * p = dynamic_cast<T*>(this))
            AcceptImpl(*p, guest);
        else
            assert(0);
        for (Container::iterator i = children.begin();
             children.end() != i;
             ++i)
            i->Accept(guest);
    }
    void
    Add(Component* const child)
    {
        child->setParent(dynamic_cast<T*>(this));
#pragma omp critical
        children.push_back(child);
    }
    void
    Clear(void)
    {
#pragma omp critical
        children.clear();
    }
};
} /* namespace eutest */

#endif /* COMPOSITE_HPP_ */
