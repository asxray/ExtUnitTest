/*
 * TestStatus_test.cpp
 *
 *  Created on: Apr 21, 2014
 *      Author: josephx
 */

#include "TestStatus.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(init)
{
    eut::TestStatus stat;
    BOOST_CHECK_EQUAL(stat.getStatus(), eut::TestStatus::WAITING);
}

BOOST_AUTO_TEST_CASE(running)
{
    eut::TestStatus stat;
    stat.setStatus(eut::TestStatus::RUNNING);
    BOOST_CHECK_EQUAL(stat.getStatus(), eut::TestStatus::RUNNING);
}
