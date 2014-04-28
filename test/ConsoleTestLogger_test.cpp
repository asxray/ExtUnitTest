
#include <boost/test/unit_test.hpp>
#include "../src/ConsoleTestLogger.h"

class CaseOne : public eut::TestCase {
#define SHOW()                                                        \
  std::cout << __FILE__ << " : " << __LINE__ << " : " << __FUNCTION__ \
            << std::endl
 public:
  CLONE(CaseOne);
  virtual ~CaseOne() {}
  virtual void SetUp() { SHOW(); }
  virtual void TearDown() { SHOW(); }
  virtual void Run() { SHOW(); }
};

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
