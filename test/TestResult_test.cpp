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

    result.setTimer("ab", 0.02);
    result.setTimer("c", 0.2);
    BOOST_CHECK_CLOSE(0.02, result.getTimer("ab"), 1e-6);
    BOOST_CHECK_CLOSE(0.2, result.getTimer("c"), 1e-6);

    BOOST_CHECK_EQUAL(eut::TestResult::WAIVED, result.getRet());
    BOOST_CHECK_EQUAL("WAIVED", result.getRetStr());
    oStr << result;
    BOOST_CHECK_EQUAL("WAIVED\n", oStr.str());

    result.setRet(eut::TestResult::PASSED);
    BOOST_CHECK_EQUAL(eut::TestResult::PASSED, result.getRet());
    result << "nothing";
    BOOST_CHECK_EQUAL("nothing", result.getLog());
    oStr.str("");
    oStr << result;
    BOOST_CHECK_EQUAL("PASSED\nnothing", oStr.str());
}
