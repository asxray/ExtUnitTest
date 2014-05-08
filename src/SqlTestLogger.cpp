#include "SqlTestLogger.h"

#include <boost/algorithm/string.hpp>
#include <time.h>

namespace eut {
SqlTestLogger::SqlTestLogger() {
  time_t CurrentTime = 0;
  time(&CurrentTime);
  CurTime = ctime(&CurrentTime);
  boost::trim(CurTime);
  Register(TestStatus::END, [&](TestCase const* const t) {
    mSqlScript << "INSERT INTO " << table
               << " (Casename,Time,Result,Duration1,Duration2,Log) VALUES "
               << "(\"" << t->getFullname() << "\",\"" << CurTime << "\",\""
               << t->getRetStr() << "\",\"" << t->getTimer(0) << "\",\""
               << t->getTimer(1) << "\",\"" << t->getErrorLog() << "\");"
               << std::endl;
  });
};

SqlTestLogger::SqlTestLogger(SqlTestLogger& t) {};
SqlTestLogger::~SqlTestLogger() {
  mSqlScript.close();
};

void SqlTestLogger::init(std::string& filepath, std::string& dbname,
                         std::string& table) {
  mSqlScript.open(filepath);
  this->table = table;
  mSqlScript << "USE " << dbname << std::endl;
}
};
