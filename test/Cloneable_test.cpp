/*
 * Cloneable_test.cpp
 *
 *  Created on: Apr 16, 2014
 *      Author: josephx
 */

#include "Cloneable.hpp"
#include <boost/test/unit_test.hpp>
#include <iostream>

class A
    : virtual public dp::Cloneable
{
public:
    virtual
    ~A() {}
    virtual void
    say()
    {
        std::cout << "A " << std::endl;
    }
};

class B
    : public A

{
public:
    virtual
    ~B() {}
    CLONE(B)
    virtual void
    say()
    {
        std::cout << "B " << std::endl;
    }
};

BOOST_AUTO_TEST_CASE(clone)
{
    B  b;
    A* bb = b.clone();
    bb->say();
    delete bb;
}
