/*
 * TestCase_test.cpp
 *
 *  Created on: Apr 22, 2014
 *      Author: josephx
 */

#include "BaseTestRunner.h"
#include "TestCase.h"
#include <boost/test/unit_test.hpp>
#include <ostream>

class CaseOne
    : public eut::TestCase
{
#define SHOW() \
    std::cout << __FILE__ << " : " << __LINE__ << " : " << __FUNCTION__ \
              << std::endl
public:
    CLONE(CaseOne);
    virtual
    ~CaseOne() {}
    virtual void
    SetUp()
    {
        SHOW();
    }
    virtual void
    TearDown()
    {
        SHOW();
    }
    virtual void
    Run()
    {
        SHOW();
    }
};

BOOST_AUTO_TEST_CASE(onecase)
{
    eut::BaseTestRunner runner;
    CaseOne             one;
    one.Accept(&runner);
}
