/*
 * BaseTestLogger_test.cpp
 *
 *  Created on: Apr 25, 2014
 *      Author: josephx
 */

#include "BaseTestLogger.h"
#include "TestCase.h"
#include <boost/test/unit_test.hpp>

namespace eut
{
class CaseOne
    : public TestCase
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
class ConsoleLogger
    : public BaseTestLogger
{
public:
    ConsoleLogger()
    {
        funcMap[TestStatus::STATUS::START] = [&](TestCase const* const t)
        {
            std::cout << "START " << t->getFullname() << std::endl;
            BOOST_CHECK_EQUAL("abc", t->getName());
        };
    };
    virtual
    ~ConsoleLogger() {};
};
} /* namespace eut */

BOOST_AUTO_TEST_CASE(name)
{
    eut::CaseOne       ac;
    ac.setName("abc");
    eut::ConsoleLogger logger;
    logger.Update(&ac);
    ac.setStatus(eut::TestStatus::START);
    logger.Update(&ac);
}
