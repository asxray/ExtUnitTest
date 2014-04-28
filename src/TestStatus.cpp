/*
 * TestStatus.cpp
 *
 *  Created on: Apr 21, 2014
 *      Author: josephx
 */

#include "TestStatus.h"

namespace eut {
std::map<TestStatus::STATUS, std::string> TestStatus::stat2str;

TestStatus::TestStatus() : status(TestStatus::WAITING) {
  if (TestStatus::stat2str.empty()) {
    TestStatus::stat2str[TestStatus::STATUS::WAITING] = "WAITING";
    TestStatus::stat2str[TestStatus::STATUS::START] = "START";
    TestStatus::stat2str[TestStatus::STATUS::SETUP] = "SETUP";
    TestStatus::stat2str[TestStatus::STATUS::RUNNING] = "RUNNING";
    TestStatus::stat2str[TestStatus::STATUS::TEARDOWN] = "TEARDOWN";
    TestStatus::stat2str[TestStatus::STATUS::END] = "END";
  }
}
TestStatus::~TestStatus() {}
TestStatus::STATUS TestStatus::getStatus() const { return (status); }
void TestStatus::setStatus(TestStatus::STATUS status) { this->status = status; }
std::string& TestStatus::Stauts2String(void) const {
  return TestStatus::stat2str.at(this->status);
}
} /* namespace eut */
