/*
 * Composite_test.cpp
 *
 *  Created on: Apr 14, 2014
 *      Author: josephx
 */

#include "Composite.hpp"
#include "Visitor.hpp"
#include <boost/test/unit_test.hpp>
#include <ostream>

class brick
    : public dp::Component
{
public:
    VISITABLE();
    brick()
        : n(1) {}
    virtual
    ~brick() {}
    int n;
};

class bigbrick
    : public brick
{
public:
    bigbrick()
        : n(2) {}
    virtual
    ~bigbrick() {}
    int n;
}
;

class wall
    : public dp::Composite
{
public:
    VISITABLECOMPOSITE();
    wall()
        : n(3) {}
    virtual
    ~wall() {}
    int n;
};

class Insect
    : public dp::BaseVisitor,
      public dp::Visitor<brick>,
      public dp::Visitor<wall>
{
public:
    Insect()
        : wallcount(0),
          brickcount(0) {}
    virtual
    ~Insect() {}
    virtual
    void
    Visit(brick& aPlace)
    {
        ++brickcount;
        BOOST_CHECK_EQUAL(aPlace.n, 1);
        std::cout << aPlace.getFullname() << std::endl;
    }
    virtual
    void
    Visit(wall& aPlace)
    {
        ++wallcount;
        BOOST_CHECK_EQUAL(aPlace.n, 3);
        std::cout << aPlace.getFullname() << std::endl;
    }
    int wallcount;
    int brickcount;
};

BOOST_AUTO_TEST_CASE(composite)
{
    Insect                    ant;
    std::shared_ptr<wall>     rootwall(new wall);
    std::shared_ptr<wall>     southwall(new wall);
    std::shared_ptr<brick>    redbrick(new brick);
    std::shared_ptr<brick>    blackbrick(new brick);
    std::shared_ptr<bigbrick> largest(new bigbrick);
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
    BOOST_CHECK_EQUAL(2, ant.wallcount);
    BOOST_CHECK_EQUAL(3, ant.brickcount);
}
