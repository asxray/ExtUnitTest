#include "SqlTestLogger.h"

#include <chrono>
#include <sstream>
#include <time.h>

namespace eut {
SqlTestLogger::SqlTestLogger() : timeinfo(0), mQ(4096), isRunning(true) {
  time_t CurrentTime = 0;
  time(&CurrentTime);
  timeinfo = localtime(&CurrentTime);
  Register(TestStatus::END, [&](TestCase const* const t) {
    std::ostringstream oStr;
    oStr << "db." << table << ".insert({Casename:\"" << t->getFullname()
         << "\",Time:" << (timeinfo->tm_year + 1900)
         << ((timeinfo->tm_mon + 1) < 10 ? "0" : "") << (timeinfo->tm_mon + 1)
         << ((timeinfo->tm_mday) < 10 ? "0" : "") << timeinfo->tm_mday
         << timeinfo->tm_hour << timeinfo->tm_min << timeinfo->tm_sec
         << ",Result:\"" << t->getRetStr() << "\""
         << ",Duration1:" << t->getTimer(0) << ",Duration2:" << t->getTimer(1)
         << ",Log:\"" << t->getErrorLog() << "\"})";

    std::string* pStr = new std::string(oStr.str());
    while (!mQ.push(pStr))
      std::this_thread::sleep_for(std::chrono::microseconds(1));
  });
  this->mThrd = std::thread([&](void) {
    while (isRunning) {
      std::string* aStr;
      while (this->mQ.pop(aStr)) {
        this->mSqlScript << *aStr << std::endl;
        delete aStr;
        std::this_thread::sleep_for(std::chrono::microseconds(1));
      };
      std::this_thread::sleep_for(std::chrono::milliseconds(1));
    };
  });
};

SqlTestLogger::SqlTestLogger(SqlTestLogger&) {};
SqlTestLogger::~SqlTestLogger() {
  this->isRunning = false;
  this->mThrd.join();
  mSqlScript.close();
};

void SqlTestLogger::init(std::string& filepath, std::string& dbname,
                         std::string& table) {
  mSqlScript.open(filepath);
  this->table = table;
  mSqlScript << "USE " << dbname << std::endl;
}
};
