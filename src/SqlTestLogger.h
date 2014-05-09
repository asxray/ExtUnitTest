#ifndef SQLTESTLOGGER_H
#define SQLTESTLOGGER_H

#include "BaseTestObserver.h"
#include "Singleton.hpp"
#include "TestCase.h"
#include <fstream>
#include <memory>

namespace eut {

class SqlTestLogger : public dp::Singleton<SqlTestLogger>,
                      public BaseTestObserver {
  SINGLETON(SqlTestLogger);
  std::string table;
  std::ofstream mSqlScript;
  std::string CurTime;
  struct tm* timeinfo;

 public:
  void init(std::string& filepath, std::string& dbname, std::string& table);
};
}
#endif /* DATABASELOG_H_ */
