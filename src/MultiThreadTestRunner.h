#ifndef MULTITHREADTESTRUNNER_H
#define MULTITHREADTESTRUNNER_H

#include "BaseTestRunner.h"
#include <boost/lockfree/queue.hpp>
#include <boost/thread.hpp>

namespace eut {
class MultiThreadTestRunner : public BaseTestRunner {
 public:
  MultiThreadTestRunner(int nThreads);
  virtual ~MultiThreadTestRunner(void);
  virtual void Visit(TestCase *const pTest);
  virtual void PostVisit(TestSuite *const pTest);

 private:
  bool isRunning;
  boost::lockfree::queue<TestCase *> mTestQ;
  boost::thread_group mThG;
};

}  // Namespace

#endif  // #ifndef MULTITHREADTESTRUNNER.H
