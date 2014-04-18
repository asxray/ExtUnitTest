/*
 * Composite_test.cpp
 *
 *  Created on: Apr 14, 2014
 *      Author: josephx
 */

#include "Composite.hpp"
#include "Visitor.hpp"
#include <iostream>

class brick
    : public eutest::Leaf<brick>
{
public:
    virtual
    ~brick() {}
    void
    Say()
    {
        if (Component const* p = getParent())
            std::cout << "   I'm in: " << p->getName() << p << std::endl;
    }
};

class bigbrick
    : public brick
{
public:
    virtual
    ~bigbrick() {}
}
;

class wall
    : public eutest::Composite<wall>
{
public:
    virtual
    ~wall() {}
    void
    Say()
    {
        if (Component const* p = getParent())
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
    Insect                      ant;
    boost::shared_ptr<wall>     rootwall(new wall);
    boost::shared_ptr<wall>     southwall(new wall);
    boost::shared_ptr<brick>    redbrick(new brick);
    boost::shared_ptr<brick>    blackbrick(new brick);
    boost::shared_ptr<bigbrick> largest(new bigbrick);
    rootwall->setName(std::string("root"));
    southwall->setName("south");
    redbrick->setName("red");
    blackbrick->setName("black");
    largest->setName("largest");
    //    redbrick->Add(blackbrick);  // won't compile. component should not add another one.
    southwall->Add(redbrick);
    southwall->Add(blackbrick);
    // southwall->Add(southwall); /// this will assert;
    rootwall->Add(southwall);
    rootwall->Add(largest);
    rootwall->Accept(ant);
    return(0);
}
