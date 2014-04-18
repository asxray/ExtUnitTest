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

namespace eutest
{
class Component
    : public BaseVisitable<>
{
protected:
    typedef std::shared_ptr<Component> spComponent;
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
    setParent(const Component& parent)
    {
        this->parent = &parent;
    }
};

class Composite
    : public Component
{
protected:
    std::list<spComponent> children;
public:
    virtual
    ~Composite() {}
    void
    Add(spComponent child)
    {
        assert(child.get() != this);
        child->setParent(*this);
#pragma omp critical
        children.push_back(child);
    }
    void
    Clear(void)
    {
#pragma omp critical
        children.clear();
    }
protected:
    template<class T>
    void
    Traverse(
        T&           visited,
        BaseVisitor& guest
        )
    {
        AcceptImpl(visited, guest);
        for (auto& i : children)
            i->Accept(guest);
    }
};
#define VISITABLECOMPOSITE() \
    virtual void Accept(eutest::BaseVisitor & guest) \
    {return Traverse(*this, guest); }
} /* namespace eutest */

#endif /* COMPOSITE_HPP_ */
