/*
 * TestSuite.h
 *
 *  Created on: Apr 13, 2014
 *      Author: josephx
 */

#ifndef TESTSUITE_H_
#define TESTSUITE_H_

#include "TestBase.h"
#include <boost/ptr_container/ptr_list.hpp>

namespace eutest
{
class TestSuite
    : public TestBase
{
public:
    TestSuite();
    virtual
    ~TestSuite();
public:
    void
    add(TestBase*);
    void
    clear();
protected:
    boost::ptr_list<TestBase> myList;
};

typedef boost::shared_ptr<TestSuite> spTestSuite;
} /* namespace eutest */

#endif /* TESTSUITE_H_ */
