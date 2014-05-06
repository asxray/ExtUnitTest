#include <boost/test/unit_test.hpp>

#include "MultiThreadTestRunner.h"
#include "TestSuite.h"
#include "CaseOne.h"
#include <string>

BOOST_AUTO_TEST_CASE(MultiThreadTestRunner) {
  BOOST_CHECK_EQUAL(0, 0);
  eut::TestSuite ts;
  ts.setName("suite");
  for (int i = 1; i < 1e4; ++i) {
    std::shared_ptr<CaseOne> tc(new CaseOne);
    tc->setName(std::to_string(i));
    ts.Add(tc);
  }
  eut::MultiThreadTestRunner mtRunner(20);
  ts.Accept(&mtRunner);
}
