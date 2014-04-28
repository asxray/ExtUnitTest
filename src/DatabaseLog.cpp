/*
 * DatabaseLog.cpp
 *
 *  Created on: Apr 24, 2014
 *      Author: ada
 */

#include "DatabaseLog.h"
#include <time.h>

#define DURATION 0
namespace eut{

DatabaseLog::DatabaseLog(std::string& dbname, std::string& user, std::string& passwd,std::string& table):
		table(table),
		sql(soci::mysql,"db="+dbname+" user="+user+" password="+passwd)

{
	try{

	}
	catch(soci::mysql_soci_error const &e)
	{
		throw std::runtime_error(e.what());
	}
	catch(...)
	{
		throw std::runtime_error("");
	}
	funcMap[TestStatus::END] =
			[&](TestCase const*const t){
			InsertRecord(t );
	};
};
DatabaseLog::DatabaseLog(DatabaseLog& t ){};
DatabaseLog::~DatabaseLog() {};

void DatabaseLog::InsertRecord(TestCase const*const t )
{
		time_t CurrentTime=0;
		time(&CurrentTime);
		char* CurTime=ctime(&CurrentTime);

		try
		{
			sql<<" insert into "<<table<<" (case_name,time,result,duration1,log) values(:c,:r,:t,:d,:l)",
					soci::use(t->getFullname()),soci::use(std::string(CurTime)),soci::use (t->getRetStr()),soci::use(t->getTimer("")),soci::use(t->getLog());
		}
		catch(soci::mysql_soci_error const &e)
		{
			throw std::runtime_error(e.what());
		}
		catch(...)
		{
			throw std::runtime_error("");
		}

}

};

