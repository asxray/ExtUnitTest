#include "MultiThreadTestRunner.h"

#include <boost/chrono.hpp>

namespace eut {
MultiThreadTestRunner::MultiThreadTestRunner(int nThreads)
    : isRunning(true), mTestQ(1024) {
  for (int i = 0; i < nThreads; ++i)
    mThG.create_thread([&](void) {
      TestCase* tc;
      while (isRunning) {
        boost::this_thread::sleep_for(boost::chrono::milliseconds(100));
        while (mTestQ.pop(tc)) {
          VisitImpl(tc);
          boost::this_thread::sleep_for(boost::chrono::milliseconds(1));
        };
      };
    });
}
MultiThreadTestRunner::~MultiThreadTestRunner() {
  isRunning = false;
  mThG.join_all();
}
void MultiThreadTestRunner::Visit(TestCase* const pTest) {
  assert(pTest);
  while (!mTestQ.push(pTest)) {
    boost::this_thread::sleep_for(boost::chrono::milliseconds(100));
  };
}
void MultiThreadTestRunner::PostVisit(eut::TestSuite* const pTest) {
  assert(pTest);
  if (nullptr != pTest->getParent()) return;
  while (!mTestQ.empty())
    boost::this_thread::sleep_for(boost::chrono::milliseconds(100));
}
}
