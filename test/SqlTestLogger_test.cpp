#include "SqlTestLogger.h"
#include "TestCase.h"
#include <boost/test/unit_test.hpp>
#include "CaseOne.h"

BOOST_AUTO_TEST_CASE(name) {
  CaseOne ac;
  ac.setName("case2");
  ac.setRet(eut::TestResult::RET::PASSED);
  std::string path("testlog.sql");
  std::string dbname("Curand");
  std::string table("test");
  eut::SqlTestLogger::Instance()->init(path, dbname, table);
  ac.setStatus(eut::TestCase::STATUS::START);
  eut::SqlTestLogger::Instance()->Update(&ac);
  ac.setStatus(eut::TestCase::STATUS::END);
  eut::SqlTestLogger::Instance()->Update(&ac);
}
