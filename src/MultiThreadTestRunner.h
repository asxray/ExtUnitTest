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

 private:
  bool isRunning;
  // typedef boost::lockfree::queue<spTestCase> mContainer;
  typedef std::list<TestCase *> mContainer;
  mContainer mTestQ;
  boost::thread_group mThG;
};

}  // Namespace

#endif  // #ifndef MULTITHREADTESTRUNNER.H
