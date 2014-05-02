/*
 * DatabaseLog.cpp
 *
 *  Created on: Apr 24, 2014
 *      Author: ada
 */

#include "DatabaseLog.h"

#include <boost/algorithm/string.hpp>
#include <time.h>

namespace eut {
DatabaseLog::DatabaseLog() {
  time_t CurrentTime = 0;
  time(&CurrentTime);
  CurTime = ctime(&CurrentTime);
  boost::trim(CurTime);
  Register(TestStatus::END, [&](TestCase const* const t) {
    mSqlScript << "INSERT INTO " << table
               << " (Casename,Time,Result,Duration1,Duration2,Log) VALUES "
               << "(\"" << t->getFullname() << "\",\"" << CurTime << "\",\""
               << t->getRetStr() << "\",\""
               << "d1\",\"d2\",\"" << t->getErrorLog() << "\");" << std::endl;
  });
};

DatabaseLog::DatabaseLog(DatabaseLog& t) {};
DatabaseLog::~DatabaseLog() {
  mSqlScript.close();
};

void DatabaseLog::init(std::string& filepath, std::string& dbname,
                       std::string& table) {
  mSqlScript.open(filepath);
  this->table = table;
  mSqlScript << "USE " << dbname << std::endl;
}
};
