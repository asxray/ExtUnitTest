#include "MultiThreadTestRunner.h"
#include <iostream>
#include <boost/chrono.hpp>

namespace eut {
MultiThreadTestRunner::MultiThreadTestRunner(int nThreads) : isRunning(true) {
  for (int i = 0; i < nThreads; ++i)
    mThG.create_thread([&](void) {
      while (this->isRunning) {
        while (!mTestQ.empty()) {
          boost::this_thread::sleep_for(boost::chrono::milliseconds(1));
          TestCase* tc = mTestQ.front();
          mTestQ.pop_front();
          // VisitImpl(tc);
          std::cout << tc->getFullname() << std::endl;
        }
        boost::this_thread::sleep_for(boost::chrono::milliseconds(1));
      };
    });
}
MultiThreadTestRunner::~MultiThreadTestRunner() {
  this->isRunning = false;
  mThG.join_all();
}
void MultiThreadTestRunner::Visit(TestCase* const pTest) {
  this->mTestQ.push_back(pTest);
}
}
