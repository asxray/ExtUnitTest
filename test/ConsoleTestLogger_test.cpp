
#include <boost/test/unit_test.hpp>
#include "../src/ConsoleTestLogger.h"
#include "CaseOne.h"

BOOST_AUTO_TEST_CASE(name) {
  CaseOne tc;
  tc.setName("CaseOne");
  tc.setStatus(eut::TestStatus::STATUS::START);
  eut::ConsoleTestLogger::Instance().Update(&tc);
  tc.setStatus(eut::TestStatus::STATUS::RUNNING);
  eut::ConsoleTestLogger::Instance().Update(&tc);
  std::string str("nothing");
  tc.setErrorLog(str);
  tc.setRet(eut::TestResult::RET::ERROR);
  tc.setStatus(eut::TestStatus::STATUS::END);
  eut::ConsoleTestLogger::Instance().Update(&tc);
}
