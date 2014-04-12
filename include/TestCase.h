/*
 * TestCase.h
 *
 *  Created on: Apr 13, 2014
 *      Author: josephx
 */

#ifndef TESTCASE_H_
#define TESTCASE_H_

#include "TestBase.h"
#include "TestResult.h"

namespace eutest
{
class TestCase
    : public TestBase
{
public:
    TestCase();
    virtual
    ~TestCase();
public:
    virtual void
    SetUp()    = 0;
    virtual void
    Exercise() = 0;
    virtual void
    Verify()   = 0;
    virtual void
    TearDown() = 0;
protected:
    boost::shared_ptr<TestResult> Result;
};

typedef boost::shared_ptr<TestCase> spTestCase;
} /* namespace eutest */

#endif /* TESTCASE_H_ */
