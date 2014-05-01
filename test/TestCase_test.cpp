/*
 * TestCase_test.cpp
 *
 *  Created on: Apr 22, 2014
 *      Author: josephx
 */

#include "../src/TestCase.h"

#include "../src/BaseTestRunner.h"
#include "CaseOne.h"
#include <boost/test/unit_test.hpp>
#include <ostream>

BOOST_AUTO_TEST_CASE(onecase) {
  eut::BaseTestRunner runner;
  CaseOne one;
  BOOST_CHECK_EQUAL(eut::TestCase::DEFAULT, one.getAttr());
  one.setAttr(eut::TestCase::WAIVED);
  BOOST_CHECK_EQUAL(eut::TestCase::WAIVED, one.getAttr());
  one.Accept(&runner);
}
