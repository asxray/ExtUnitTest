#include <boost/test/unit_test.hpp>
#include "../src/App.h"
#include "CaseOne.h"
#include "../src/RootTestSuite.h"
#include <memory>

BOOST_AUTO_TEST_CASE(App) {
  std::shared_ptr<CaseOne> acase(new CaseOne);
  eut::RootTestSuite::Instance()->Add(acase);
  int argc = 2;
  char const* argv[argc];
  argv[0] = "none";
  {
    argv[1] = "-h";
    eut::App app(argc, argv);
    BOOST_CHECK_EQUAL(0, app.Exec());
  }
  {
    argv[1] = "--list";
    eut::App app(argc, argv);
    BOOST_CHECK_EQUAL(0, app.Exec());
  }
  {
    argv[1] = "-j4";
    eut::App app(argc, argv);
    BOOST_CHECK_EQUAL(0, app.Exec());
  }
  {
    argv[1] = "-j1";
    eut::App app(argc, argv);
    BOOST_CHECK_EQUAL(0, app.Exec());
  }
}
