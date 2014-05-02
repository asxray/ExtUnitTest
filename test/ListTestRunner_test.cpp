#include <boost/test/unit_test.hpp>

#include "../src/ListTestRunner.h"

#include "../src/TestSuite.h"
#include "CaseOne.h"

BOOST_AUTO_TEST_CASE(ListTestRunner) {
  BOOST_CHECK_EQUAL(0, 0);
  eut::TestSuite ts;
  ts.setName("suite");
  for (int i = 0; i < 100; ++i) {
    std::shared_ptr<CaseOne> tc(new CaseOne);
    tc->setName(std::to_string(i));
    ts.Add(tc);
  }
  eut::ListTestRunner ltRunner;
  ts.Accept(&ltRunner);
  ltRunner.Print();
  BOOST_CHECK_EQUAL(100, ltRunner.Count());
}
