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
    : public virtual eutest::Component,
      public eutest::BaseVisitable<>
{
public:
    EUTEST_VISITABLE();
    brick() {}
    virtual
    ~brick() {}
};

class wall
    : virtual public eutest::Composite<brick>
{
public:
    wall() {}
    virtual
    ~wall() {}
    virtual void
    Accept(eutest::BaseVisitor& guest)
    {
        AcceptImpl(*this, guest);
        for (ChildIter i = children.begin();
             children.end() != i;
             ++i)
            if (brick * p = dynamic_cast<brick*>(&*i))
                p->Accept(guest);
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
        std::cout << " clambing on brick " << aPlace.getName() << std::endl;
    }
    virtual
    void
    Visit(wall& aPlace)
    {
        std::cout << " clambing on wall " << aPlace.getName() << std::endl;
    }
};

int
main()
{
    Insect ant;
    wall   southwall;
    southwall.setName("south wall");
    brick* redbrick   = new brick;
    redbrick->setName("red brick");
    brick* blackbrick = new brick;
    blackbrick->setName("black brick");
    southwall.Add(redbrick);
    southwall.Add(blackbrick);
    southwall.Accept(ant);
    return(0);
}
