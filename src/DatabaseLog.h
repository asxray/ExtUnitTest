/*
 * DatabaseLog.h
 *
 *  Created on: Apr 24, 2014
 *      Author: ada
 */

#ifndef DATABASELOG_H_
#define DATABASELOG_H_
#include "Singleton.hpp"
#include "TestCase.h"
#include <../soci/core/soci.h>
#include <../soci/backends/mysql/soci-mysql.h>
#include "BaseTestLogger.h"

namespace eut
{


class DatabaseLog:
		public dp::Singleton<DatabaseLog>,
public BaseTestLogger
{
	SINGLETON(DatabaseLog);
	std::string table;
	soci::session sql;
public:
	DatabaseLog(std::string& dbname, std::string& user, std::string& passwd,std::string& table);
	void InsertRecord(TestCase const*const t);


};


}
#endif /* DATABASELOG_H_ */
