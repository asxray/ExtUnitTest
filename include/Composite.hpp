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
{
public:
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
    setParent(Component*& parent)
    {
        this->parent = parent;
    }
protected:
    std::string name;
    Component*  parent;
};

template<class T>
class Composite
    : virtual public Component,
      virtual public T
{
public:
    Composite()
    {}
    virtual
    ~Composite() {}
    void
    Add(T*& aChild)
    {
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
    typedef boost::ptr_list<Component> Container;
    typedef Container::iterator        ChildIter;
    Container children;
};
} /* namespace eutest */

#endif /* COMPOSITE_HPP_ */
