#include "MultiThreadTestRunner.h"

#include <boost/chrono.hpp>
#include <boost/interprocess/sync/scoped_lock.hpp>

namespace eut {
MultiThreadTestRunner::MultiThreadTestRunner(int nThreads)
    : mTestQ(1024), isRunning(true), isVisited(false), cnt(0) {
  for (int i = 0; i < nThreads; ++i)
    mThG.create_thread([&](void) {
      TestCase* tc;
      while (isRunning) {
        boost::this_thread::sleep_for(boost::chrono::milliseconds(1));
        while (mTestQ.pop(tc)) {
          VisitImpl(tc);
          boost::this_thread::sleep_for(boost::chrono::nanoseconds(1));
          --cnt;
        }  // pop
        if (0 == cnt && isVisited) this->cond_empty.notify_all();
      }  // isRunning
    });
}
MultiThreadTestRunner::~MultiThreadTestRunner() {
  isRunning = false;
  mThG.join_all();
}
void MultiThreadTestRunner::Visit(TestCase* const pTest) {
  assert(pTest);
  while (!mTestQ.push(pTest)) {
    boost::this_thread::sleep_for(boost::chrono::milliseconds(1));
  }
  ++cnt;
}
void MultiThreadTestRunner::Wait() {
  isVisited = true;
  boost::interprocess::scoped_lock<boost::interprocess::interprocess_mutex>
      aLock(this->mux);
  this->cond_empty.wait(aLock);
}
}
