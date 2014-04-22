/*
 * TestResource_test.cpp
 *
 *  Created on: Apr 22, 2014
 *      Author: josephx
 */

#include "TestResource.h"
#include <boost/test/unit_test.hpp>

class SomeRes
    : public eut::TestResource
{
public:
    virtual
    ~SomeRes() {}
    virtual void
    SetUp()
    {
        a = 1;
    }
    virtual void
    TearDown()
    {
        a = 2;
    }
public:
    int a;
};

BOOST_AUTO_TEST_CASE(testresource)
{
    SomeRes res;
    res.SetUp();
    BOOST_CHECK_EQUAL(1, res.a);
    res.TearDown();
    BOOST_CHECK_EQUAL(2, res.a);
}
