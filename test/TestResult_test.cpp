/*
 * TestResult_test.cpp
 *
 *  Created on: Apr 21, 2014
 *      Author: josephx
 */

#include "TestResult.h"
#include <boost/test/unit_test.hpp>
#include <sstream>

BOOST_AUTO_TEST_CASE(testresult)
{
    std::ostringstream oStr;
    eut::TestResult    result;
    BOOST_CHECK_EQUAL(eut::TestResult::WAIVED, result.getRet());
    oStr << result;
    BOOST_CHECK_EQUAL("WAIVED\n", oStr.str());
    result.setRet(eut::TestResult::PASSED);
    BOOST_CHECK_EQUAL(eut::TestResult::PASSED, result.getRet());
    result << "nothing";
    BOOST_CHECK_EQUAL("nothing", result.getErrorlog());
    oStr.str("");
    oStr << result;
    BOOST_CHECK_EQUAL("PASSED\nnothing", oStr.str());
}
