#include "ListTestRunner.h"

#include <iostream>

namespace eut {
ListTestRunner::~ListTestRunner(void) {};
void ListTestRunner::Visit(TestCase* const pTest) {
  mTestList.push_back(pTest->getFullname());
}
unsigned int ListTestRunner::Count() { return mTestList.size(); }
void ListTestRunner::Print() const {
  for (auto& i : mTestList) std::cout << i << std::endl;
}
}
