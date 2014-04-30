#ifndef CONSOLETESTLOGGER_H
#define CONSOLETESTLOGGER_H

#include "BaseTestObserver.h"
#include "Singleton.hpp"

namespace eut {
class ConsoleTestLogger : public BaseTestObserver,
                          public dp::Singleton<ConsoleTestLogger> {
  SINGLETON(ConsoleTestLogger);
};
}  // namespace
#endif
