/*
 * TestCase_test.cpp
 *
 *  Created on: Apr 22, 2014
 *      Author: josephx
 */

#include "TestCase.h"
#include <boost/test/unit_test.hpp>

class CaseOne
    : public eut::TestCase
{
public:
    CLONE(CaseOne);
    virtual
    ~CaseOne() {}
    virtual void
    SetUp()
    {
        setStatus(eut::TestStatus::RUNNING);
    }
    virtual void
    TearDown()
    {}
    virtual void
    Run()
    {
        *this << "NOTHING";
        setPassed(true);
    }
};

BOOST_AUTO_TEST_CASE(onecase)
{
    CaseOne                        one;
    std::shared_ptr<eut::TestCase> pCase(one.clone());
    BOOST_REQUIRE(pCase.get());
    BOOST_CHECK_EQUAL(false, pCase->isPassed());
    BOOST_CHECK_EQUAL(eut::TestStatus::WAITING, pCase->getStatus());
    pCase->setStatus(eut::TestStatus::START);
    BOOST_CHECK_EQUAL(eut::TestStatus::START, pCase->getStatus());
    pCase->SetUp();
    BOOST_CHECK_EQUAL(false, pCase->isPassed());
    BOOST_CHECK_EQUAL(eut::TestStatus::RUNNING, pCase->getStatus());
    BOOST_CHECK_EQUAL("FAILED\n", pCase->ToString());
    pCase->Run();
    pCase->TearDown();
    pCase->setStatus(eut::TestStatus::END);
    BOOST_CHECK_EQUAL(eut::TestStatus::END, pCase->getStatus());
    BOOST_CHECK_EQUAL(true, pCase->isPassed());
    BOOST_CHECK_EQUAL("PASSED\nNOTHING", pCase->ToString());
}
