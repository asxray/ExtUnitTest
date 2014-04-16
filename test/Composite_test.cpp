/*
 * Composite_test.cpp
 *
 *  Created on: Apr 14, 2014
 *      Author: josephx
 */

#include "Composite.hpp"
#include "Visitor.hpp"
#include <boost/lambda/lambda.hpp>
#include <iostream>

class brick
    : public eutest::Leaf<brick>
{
public:
    void
    Say()
    {
        if (Component const* const p = getParent())
            std::cout << "   I'm in: " << p->getName() << p << std::endl;
    }
};

class bigbrick
    : public brick
{};

class wall
    : public eutest::Composite<wall>
{
public:
    void
    Say()
    {
        if (Component const* const p = getParent())
            std::cout << "   I'm in: " << p->getName() << p << std::endl;
    }
};

class Insect
    : public eutest::BaseVisitor,
      public eutest::Visitor<brick>,
      public eutest::Visitor<wall>
{
public:
    virtual
    void
    Visit(brick& aPlace)
    {
        std::cout << " clambing on brick: " << aPlace.getName() << std::endl;
        aPlace.Say();
    }
    virtual
    void
    Visit(wall& aPlace)
    {
        std::cout << " clambing on wall: " << aPlace.getName() << std::endl;
        aPlace.Say();
    }
};

int
main()
{
    Insect    ant;
    wall      rootwall;
    wall*     southwall  = new wall;
    brick*    redbrick   = new brick;
    brick*    blackbrick = new brick;
    bigbrick* largest    = new bigbrick;
    rootwall.setName("north");
    southwall->setName("south");
    redbrick->setName("red");
    blackbrick->setName("black");
    largest->setName("largest");
    //    redbrick->Add(blackbrick);  // won't compile. component should not add another one.
    southwall->Add(redbrick);
    southwall->Add(blackbrick);
    rootwall.Add(southwall);
    rootwall.Add(largest);
    rootwall.Accept(ant);
    return(0);
}
