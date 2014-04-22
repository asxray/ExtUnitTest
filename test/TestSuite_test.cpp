/*
 * TestSuite_test.cpp
 *
 *  Created on: Apr 22, 2014
 *      Author: josephx
 */

#include "TestCase.h"
#include "TestSuite.h"
#include <boost/test/unit_test.hpp>
#include <memory>

namespace eut
{
class Case1
    : public eut::TestCase
{
public:
    CLONE(Case1);
    virtual
    ~Case1() {}
    virtual void
    SetUp() {}
    virtual void
    TearDown() {}
    virtual void
    Run() {}
};
} /* namespace eut */

BOOST_AUTO_TEST_CASE(testsuite)
{
    std::shared_ptr<eut::TestSuite> s1(new eut::TestSuite);
    s1->setName("s1");
    std::shared_ptr<eut::TestSuite> s2(new eut::TestSuite);
    s2->setName("s2");
    std::shared_ptr<eut::TestCase>  c1(new eut::Case1);
    c1->setName("c1");
    s1->Add(s2);
    s2->Add(c1);
}
