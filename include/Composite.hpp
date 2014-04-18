/*
 * Composite.hpp
 *
 *  Created on: Apr 14, 2014
 *      Author: josephx
 */

#ifndef COMPOSITE_HPP_
#define COMPOSITE_HPP_

#include "Visitor.hpp"
#include <boost/shared_ptr.hpp>
#include <list>
#include <string>

namespace eutest
{
class Component
    : public BaseVisitable<>
{
public:
    typedef boost::shared_ptr<Component> spComponent;
protected:
    std::string      name;
    Component const* parent;
public:
    Component()
        : parent(0) {}
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
public:
    virtual
    ~Leaf() {}
    virtual void
    Accept(BaseVisitor& guest)
    {
        AcceptImpl(dynamic_cast<T&>(*this), guest);
    }
};

template<class T>
class Composite
    : public Component
{
protected:
    typedef std::list<spComponent> Container;
    Container children;
public:
    virtual
    ~Composite() {}
    virtual void
    Accept(BaseVisitor& guest)
    {
        AcceptImpl(dynamic_cast<T&>(*this), guest);
        for (auto& i : children)
            i->Accept(guest);
    }
    void
    Add(spComponent child)
    {
        assert(child.get() != this);
        child->setParent(this);
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
