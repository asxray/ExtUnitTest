/*
 * TestResult_test.cpp
 *
 *  Created on: Apr 21, 2014
 *      Author: josephx
 */

#include "../src/TestResult.h"
#include <boost/test/unit_test.hpp>
#include <sstream>

BOOST_AUTO_TEST_CASE(testresult) {
  eut::TestResult result;

  BOOST_CHECK_EQUAL(eut::TestResult::WAIVED, result.getRet());
  BOOST_CHECK_EQUAL("WAIVED", result.getRetStr());

  result.setTimer(0, 0.02);
  result.setTimer(1, 0.2);
  BOOST_CHECK_CLOSE(0.02, result.getTimer(0), 1e-6);
  BOOST_CHECK_CLOSE(0.2, result.getTimer(1), 1e-6);

  result.setRet(eut::TestResult::PASSED);
  BOOST_CHECK_EQUAL(eut::TestResult::PASSED, result.getRet());
  std::string str("nothing");
  result.setErrorLog(str);
  BOOST_CHECK_EQUAL("nothing", result.getErrorLog());
}
