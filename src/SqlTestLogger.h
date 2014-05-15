#ifndef SQLTESTLOGGER_H
#define SQLTESTLOGGER_H

#include "BaseTestObserver.h"
#include "Singleton.hpp"
#include "TestCase.h"
#include <boost/lockfree/queue.hpp>
#include <fstream>
#include <memory>
#include <string>
#include <thread>

namespace eut {

class SqlTestLogger : public dp::Singleton<SqlTestLogger>,
                      public BaseTestObserver {
  SINGLETON(SqlTestLogger);
  std::string table;
  std::ofstream mSqlScript;
  std::string CurTime;
  struct tm* timeinfo;
  std::thread mThrd;
  boost::lockfree::queue<std::string*> mQ;
  bool isRunning;

 public:
  void init(std::string& filepath, std::string& dbname, std::string& table);
};
}
#endif /* DATABASELOG_H_ */
