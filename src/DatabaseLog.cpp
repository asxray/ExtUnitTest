/*
 * DatabaseLog.cpp
 *
 *  Created on: Apr 24, 2014
 *      Author: ada
 */

#include "DatabaseLog.h"
#include <boost/algorithm/string.hpp>
#include <boost/bind.hpp>
#include <time.h>

namespace eut {

DatabaseLog::DatabaseLog() : isRunning(true) {
  Register(TestStatus::END,
           [&](TestCase const *const t) { AddToThreadPool(t); });
  CaseQueue.reset(new boost::lockfree::queue<TestCase const *>(4096));
  mThread.reset(new boost::thread(boost::bind(&DatabaseLog::ThreadLoop, this)));
};
DatabaseLog::DatabaseLog(DatabaseLog &t) {};
DatabaseLog::~DatabaseLog() {
  isRunning = false;
  mThread->join();
};

void DatabaseLog::ConnectDB(std::string dbname, std::string user,
                            std::string passwd, std::string table) {
  this->table = table;
  try {
    mSql.reset(new soci::session(
        soci::mysql, "db=" + dbname + " user=" + user + " password=" + passwd));
  }
  catch (soci::mysql_soci_error const &e) {
    throw std::runtime_error(e.what());
  }
  catch (...) {
    throw std::runtime_error("");
  }
}

void DatabaseLog::ThreadLoop() {
  while (isRunning || !CaseQueue->empty()) {
    TestCase *tt;
    CaseQueue->pop(tt);
    InsertRecord(tt);
  }
}

void DatabaseLog::AddToThreadPool(TestCase const *const t) {
  CaseQueue->push(t);
}

void DatabaseLog::InsertRecord(TestCase const *const t) {
  time_t CurrentTime = 0;
  time(&CurrentTime);
  std::string CurTime = std::string(ctime(&CurrentTime));
  boost::trim(CurTime);
  std::string fullname = t->getFullname();

  try {
    (*mSql) << "insert into " << table
            << " (case_name,time,result) values(:c,:t,:r)",
        soci::use(fullname /*t->getFullname()*/),
        soci::use(std::string(CurTime)),
        soci::use(std::string(CurTime) /*t->getRetStr()*/);
  }
  catch (soci::mysql_soci_error const &e) {
    throw std::runtime_error(e.what());
  }
  catch (...) {
    throw std::runtime_error("");
  }
}
};
