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
DatabaseLog::DatabaseLog()
    : isRunning(true), CaseQueue(65536), mThread([&]() { ThreadLoop(); }) {
  Register(TestStatus::END, [&](TestCase const *const t) {
    while (!CaseQueue.push(t)) {
      boost::this_thread::sleep_for(boost::chrono::seconds(1));
    }
  });
};
DatabaseLog::DatabaseLog(DatabaseLog &t) {};
DatabaseLog::~DatabaseLog() {
  isRunning = false;
  mThread.join();
};
void DatabaseLog::ConnectDB(std::string &dbname, std::string &user,
                            std::string &passwd, std::string &table) {
  this->table = table;
  try {
    mSql.reset(new soci::session(
        soci::mysql, "db=" + dbname + " user=" + user + " password=" + passwd));
  }
  catch (soci::mysql_soci_error const &e) {
    throw std::runtime_error(e.what());
  }
  catch (...) {
    throw std::runtime_error("Unknown Exception");
  }
}

void DatabaseLog::ThreadLoop() {
  TestCase const *tt;
  while (isRunning) {
    boost::this_thread::sleep_for(boost::chrono::seconds(1));
    while (CaseQueue.pop(tt)) {
      InsertRecord(tt);
      boost::this_thread::sleep_for(boost::chrono::milliseconds(1));
    }
  }
}

void DatabaseLog::InsertRecord(TestCase const *const t) {
  time_t CurrentTime = 0;
  time(&CurrentTime);
  std::string CurTime(ctime(&CurrentTime));
  boost::trim(CurTime);

  try {
    (*mSql) << "insert into " << table
            << " (case_name,time,result) values(:c,:t,:r)",
        soci::use(t->getFullname()), soci::use(std::string(CurTime)),
        soci::use(t->getRetStr());
  }
  catch (soci::mysql_soci_error const &e) {
    throw std::runtime_error(e.what());
  }
  catch (...) {
    throw std::runtime_error("");
  }
}
};
