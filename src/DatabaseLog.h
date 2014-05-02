/*
 * DatabaseLog.h
 *
 *  Created on: Apr 24, 2014
 *      Author: ada
 */

#ifndef DATABASELOG_H_
#define DATABASELOG_H_

#include "BaseTestObserver.h"
#include "Singleton.hpp"
#include "TestCase.h"
#include <fstream>
#include <memory>

namespace eut {

class DatabaseLog : public dp::Singleton<DatabaseLog>, public BaseTestObserver {
  SINGLETON(DatabaseLog);
  std::string table;
  std::ofstream mSqlScript;
  std::string CurTime;

 public:
  void init(std::string& filepath, std::string& dbname, std::string& table);
};
}
#endif /* DATABASELOG_H_ */
