/*
 * Cloneable_test.cpp
 *
 *  Created on: Apr 16, 2014
 *      Author: josephx
 */

#include "Cloneable.hpp"
#include <iostream>
class A
    : virtual public eutest::Cloneable
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
    CLONEABLE(B)
    virtual void
    say()
    {
        std::cout << "B " << std::endl;
    }
};

int
main()
{
    B  b;
    A* bb = b.clone();
    bb->say();
    delete bb;
}
