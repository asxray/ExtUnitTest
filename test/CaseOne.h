#ifndef CASEONE_H
#define CASEONE_H

#include "../src/TestCase.h"

#include <iostream>

class CaseOne : public eut::TestCase {
#define SHOW() std::cout << __FUNCTION__ << " " << getName() << std::endl
 public:
  CLONE(CaseOne);
  virtual ~CaseOne() {}
  virtual void SetUp() { SHOW(); }
  virtual void TearDown() { SHOW(); }
  virtual void Run() { SHOW(); }
};

#endif  // CASEONE_H
