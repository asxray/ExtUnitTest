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
#include "BaseTestObserver.h"
#include <boost/thread/thread.hpp>
#include <boost/asio/io_service.hpp>
#include <boost/lockfree/queue.hpp>

namespace eut
{


class DatabaseLog:
		public dp::Singleton<DatabaseLog>,
public BaseTestObserver
{
	SINGLETON(DatabaseLog);
	std::string table;
	soci::session* sql;
//	boost::thread_group tg;
//	boost::asio::io_service ioService;
//	boost::asio::io_service::work* work;
	boost::thread* thread;
	boost::lockfree::queue <TestCase const*> *CaseQueue;
public:
	void AddToThreadPool(TestCase const*const t);
	void InsertRecord(TestCase const*const t);
	void InsertionThread();
	void ThreadLoop();
	void ConnectDB(std::string dbname, std::string user, std::string passwd,std::string table);
private:
	bool isRunning;

};


}
#endif /* DATABASELOG_H_ */
