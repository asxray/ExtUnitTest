#include "ConsoleTestLogger.h"
#include <iostream>
namespace eut {
ConsoleTestLogger::ConsoleTestLogger() {
  this->Register(TestStatus::STATUS::START, [&](TestCase const* const aCase) {
    std::cout << "&&&& RUNNING " << aCase->getFullname() << std::endl;
  });
  this->Register(TestStatus::STATUS::END, [&](TestCase const* const aCase) {
    if (!aCase->getErrorLog().empty())
      std::cout << aCase->getErrorLog() << std::endl;
    std::cout << "&&&& " << aCase->getRetStr() << " " << aCase->getFullname()
              << std::endl;
  });
}
ConsoleTestLogger::~ConsoleTestLogger() {};
}  // namespace
