/*
 * TestResult_test.cpp
 *
 *  Created on: Apr 21, 2014
 *      Author: josephx
 */

#include "TestResult.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(testresult)
{
    eut::TestResult result;
    BOOST_CHECK_EQUAL(false, result.isPassed());
    BOOST_CHECK_EQUAL("FAILED\n", result.ToString());
    result.setPassed(true);
    BOOST_CHECK_EQUAL(true, result.isPassed());
    BOOST_CHECK_EQUAL("PASSED\n", result.ToString());
}
