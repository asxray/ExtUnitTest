/*
 * TestStatus_test.cpp
 *
 *  Created on: Apr 21, 2014
 *      Author: josephx
 */

#include "TestStatus.h"
#include <boost/test/unit_test.hpp>

class MyStatus : public eut::TestStatus {
 public:
  virtual ~MyStatus() {}
};

BOOST_AUTO_TEST_CASE(init) {
  MyStatus stat;
  BOOST_CHECK_EQUAL(stat.getStatus(), eut::TestStatus::WAITING);
  stat.setStatus(eut::TestStatus::RUNNING);
  BOOST_CHECK_EQUAL(stat.getStatus(), eut::TestStatus::RUNNING);
  BOOST_CHECK_EQUAL(stat.Stauts2String(), "RUNNING");
}
