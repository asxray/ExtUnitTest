#ifndef LISTTESTRUNNER_H
#define LISTTESTRUNNER_H

#include "BaseTestRunner.h"
#include <list>
#include <string>

namespace eut {
class ListTestRunner : public BaseTestRunner {
 public:
  virtual ~ListTestRunner(void);
  virtual void Visit(TestCase* const pTest);
  unsigned int Count();
  void Print() const;

 public:
  std::list<std::string> mTestList;
};
}

#endif  // LISTTESTRUNNER_H
