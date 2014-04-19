/*
 * Visitor_test.cpp
 *
 *  Created on: Apr 14, 2014
 *      Author: josephx
 */

#include "Visitor.hpp"
#include <iostream>

class House
    : public::dp::BaseVisitable<>
{
public:
    virtual
    ~House() {}
    VISITABLE();
    House()
        : height(3) {}
    const int height;
};

class Cleaner
    : public::dp::BaseVisitor,
      public::dp::Visitor<House>
{
public:
    virtual
    ~Cleaner() {}
    void
    Visit(House& aHouse)
    {
        std::cout << aHouse.height << std::endl;
    }
};

int
main()
{
    House   whiteHouse;
    Cleaner bush;
    whiteHouse.Accept(bush);
    return(0);
}
