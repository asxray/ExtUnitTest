#include "DatabaseLog.h"
#include "TestCase.h"
#include <boost/test/unit_test.hpp>
#include "CaseOne.h"

BOOST_AUTO_TEST_CASE(name) {
  CaseOne ac;
  ac.setName("case2");
  ac.setRet(eut::TestResult::RET::PASSED);
  std::string dbname("CUFFT");
  std::string user("root");
  std::string passwd("1");
  std::string table("test");
  eut::DatabaseLog::Instance().ConnectDB(dbname, user, passwd, table);
  ac.setStatus(eut::TestCase::STATUS::START);
  eut::DatabaseLog::Instance().Update(&ac);
  ac.setStatus(eut::TestCase::STATUS::END);
  eut::DatabaseLog::Instance().Update(&ac);
}
