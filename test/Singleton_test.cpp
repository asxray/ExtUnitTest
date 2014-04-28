#include "Singleton.hpp"
#include <boost/test/unit_test.hpp>

class testSingleton : public dp::Singleton<testSingleton> {
  SINGLETON(testSingleton);

 public:
  std::string say() { return ("hello"); }
};

testSingleton::testSingleton() {}
testSingleton::testSingleton(testSingleton& t) {}
testSingleton::~testSingleton() {}

BOOST_AUTO_TEST_CASE(singleton) {
  // testSingleton ats; // can't compile
  BOOST_CHECK_EQUAL("hello", testSingleton::Instance().say());
}
