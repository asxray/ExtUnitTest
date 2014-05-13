#ifndef MULTITHREADTESTRUNNER_H
#define MULTITHREADTESTRUNNER_H

#include "BaseTestRunner.h"
#include <atomic>
#include <boost/interprocess/sync/interprocess_condition.hpp>
#include <boost/interprocess/sync/interprocess_mutex.hpp>
#include <boost/lockfree/queue.hpp>
#include <boost/thread.hpp>

namespace eut {
class MultiThreadTestRunner : public BaseTestRunner {
 public:
  MultiThreadTestRunner(int nThreads);
  virtual ~MultiThreadTestRunner(void);
  virtual void Visit(TestCase *const pTest);
  virtual void Wait(void);

 private:
  boost::interprocess::interprocess_condition cond_empty;
  boost::interprocess::interprocess_mutex mux;
  boost::lockfree::queue<TestCase *> mTestQ;
  boost::thread_group mThG;
  std::atomic_bool isRunning;
  std::atomic_bool isVisited;
  std::atomic_long cnt;
};

}  // Namespace

#endif  // #ifndef MULTITHREADTESTRUNNER.H
