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
#include <../soci/src/backends/mysql/soci-mysql.h>
#include <../soci/src/core/soci.h>
#include <boost/lockfree/queue.hpp>
#include <boost/thread/thread.hpp>
#include <memory>

namespace eut {

class DatabaseLog : public dp::Singleton<DatabaseLog>, public BaseTestObserver {
  SINGLETON(DatabaseLog);
  bool isRunning;
  std::string table;
  std::shared_ptr<soci::session> mSql;
  std::shared_ptr<boost::thread> mThread;
  std::shared_ptr<boost::lockfree::queue<TestCase const*> > CaseQueue;

 public:
  void InsertRecord(TestCase const* const t);
  void ThreadLoop();
  void ConnectDB(std::string dbname, std::string user, std::string passwd,
                 std::string table);
};
}
#endif /* DATABASELOG_H_ */
