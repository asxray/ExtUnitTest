#include "ConsoleTestLogger.h"
#include <iostream>
namespace eut {
ConsoleTestLogger::ConsoleTestLogger() {
  this->Register(TestStatus::STATUS::START, [&](TestCase const* const aCase) {
    std::cout << "&&&& RUNNING " << aCase->getName() << std::endl;
  });
  this->Register(TestStatus::STATUS::END, [&](TestCase const* const aCase) {
    std::cout << aCase->getLog() << "&&&& " << aCase->getRetStr() << " "
              << aCase->getName() << std::endl;
  });
}
ConsoleTestLogger::~ConsoleTestLogger() {};
}  // namespace
