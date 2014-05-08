/*
 * TestResult.cpp
 *
 *  Created on: Apr 21, 2014
 *      Author: josephx
 */

#include "TestResult.h"
#include <ostream>

namespace eut {
std::map<TestResult::RET, std::string> TestResult::ret2Str;

TestResult::TestResult() : ret(RET::WAIVED) {
  for (auto& i : this->timer) i = 0;
  if (ret2Str.empty()) {
    ret2Str[TestResult::RET::PASSED] = "PASSED";
    ret2Str[TestResult::RET::FAILED] = "FAILED";
    ret2Str[TestResult::RET::ERROR] = "ERROR";
    ret2Str[TestResult::RET::WAIVED] = "WAIVED";
  }
}
TestResult::~TestResult() {}

TestResult::RET TestResult::getRet() const { return (ret); }

void TestResult::setRet(RET result) { this->ret = result; }

const std::string& TestResult::getRetStr() const {
  return (ret2Str.at(this->ret));
}

double TestResult::getTimer(const int idx) const { return (timer.at(idx)); }

void TestResult::setTimer(const int idx, const double n) {
  this->timer.at(idx) = n;
}

const std::string& TestResult::getErrorLog() const { return this->ErrorLog; }
void TestResult::setErrorLog(const std::string& slog) { this->ErrorLog = slog; }
} /* namespace eut */
