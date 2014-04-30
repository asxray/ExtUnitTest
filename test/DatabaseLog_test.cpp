#include "DatabaseLog.h"
#include "TestCase.h"
#include <boost/test/unit_test.hpp>

namespace eut {

class CaseTwo : public TestCase {
#define SHOW()                                                        \
  std::cout << __FILE__ << " : " << __LINE__ << " : " << __FUNCTION__ \
            << std::endl
 public:
  CLONE(CaseTwo);
  virtual ~CaseTwo() {}
  virtual void SetUp() { SHOW(); }
  virtual void TearDown() { SHOW(); }
  virtual void Run() { SHOW(); }
};
}

BOOST_AUTO_TEST_CASE(name) {
  eut::CaseTwo ac;
  ac.setName("case2");
  ac.setRet(eut::TestResult::RET::PASSED);
  eut::DatabaseLog::Instance().ConnectDB(std::string("CUFFT"),
                                         std::string("root"), std::string("1"),
                                         std::string("test"));
  ac.setStatus(eut::TestCase::STATUS::START);
  eut::DatabaseLog::Instance().Update(&ac);
  ac.setStatus(eut::TestCase::STATUS::END);
  eut::DatabaseLog::Instance().Update(&ac);
}
