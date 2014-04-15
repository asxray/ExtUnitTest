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
    : virtual public eutest::Leaf<brick>
{
public:
    brick() {}
    virtual
    ~brick() {}
    void
    Say()
    {
    	if (Component* p = getParent())
    	std::cout << "I'm in " << p->getName() << std::endl;
    }
};

class wall
    : virtual public eutest::Composite<wall>
{
public:
    wall() {}
    virtual
    ~wall() {}
    void
    Say()
    {
    	if (Component* p = getParent())
    	std::cout << "I'm in " << p->getName() << std::endl;
    }
};

class Insect
    : public eutest::BaseVisitor,
      public eutest::Visitor<brick>,
      public eutest::Visitor<wall>
{
public:
    Insect() {}
    virtual
    ~Insect() {}
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
    Insect ant;
    wall*  northwall  = new wall;
    wall*  southwall  = new wall;
    brick* redbrick   = new brick;
    brick* blackbrick = new brick;
    southwall->setName("south wall");
    northwall->setName("North Wall");
    redbrick->setName("red brick");
    blackbrick->setName("black brick");
//    redbrick->Add(blackbrick);  // won't compile. component should not add another one.
    southwall->Add(redbrick);
    southwall->Add(blackbrick);
    northwall->Add(southwall);
    northwall->Accept(ant);
    delete northwall;
    return(0);
}
