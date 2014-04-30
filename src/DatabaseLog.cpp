/*
 * DatabaseLog.cpp
 *
 *  Created on: Apr 24, 2014
 *      Author: ada
 */

#include "DatabaseLog.h"
#include <time.h>
#include <boost/algorithm/string.hpp>
#include <boost/bind.hpp>
namespace eut{

DatabaseLog::DatabaseLog():isRunning(true) {};
DatabaseLog::DatabaseLog(DatabaseLog& t) {};
DatabaseLog::~DatabaseLog() {
	isRunning = false;
	thread->join();
//	ioService.stop();
//	tg.join_all();
	delete sql;
	delete thread;
	delete CaseQueue;
//	delete work;


};

void DatabaseLog::ConnectDB(std::string dbname, std::string user, std::string passwd,std::string table)
{
	this->table=table;
	try{
		sql=new soci::session(soci::mysql,"db="+dbname+" user="+user+" password="+passwd);
	}
	catch(soci::mysql_soci_error const &e)
	{
		throw std::runtime_error(e.what());
	}
	catch(...)
	{
		throw std::runtime_error("");
	}

		Register(TestStatus::END ,
				[&](TestCase const*const t){AddToThreadPool(t);});
		CaseQueue=new boost::lockfree::queue <TestCase const*>(4096);
		thread=new boost::thread(boost::bind(&DatabaseLog::ThreadLoop,this));
//		work=new boost::asio::io_service::work(ioService);
//		tg.create_thread(boost::bind(&boost::asio::io_service::run, &ioService));

}

void DatabaseLog::ThreadLoop()
{
	while(isRunning)
	{
			if(!CaseQueue->empty())
			{
				TestCase * tt;
				CaseQueue->pop(tt);
				InsertRecord(tt);
			}
	};
}

void DatabaseLog::AddToThreadPool(TestCase const*const t)
{
//	ioService.post(boost::bind(&DatabaseLog::InsertRecord,this,t));
	CaseQueue->push(t);
}

//void DatabaseLog::InsertRecord(TestCase const*const t )
//{
//	std::cout<<"inserted"<<std::endl;
//}

void DatabaseLog::InsertRecord(TestCase const*const t )
{
		time_t CurrentTime=0;
		time(&CurrentTime);
		std::string CurTime=std::string(ctime(&CurrentTime));
		boost::trim(CurTime);
		std::string fullname=t->getFullname();

		try
		{
			(*sql)<<"insert into "<<table<<" (case_name,time,result) values(:c,:t,:r)",
					soci::use(fullname/*t->getFullname()*/),soci::use(std::string(CurTime)),soci::use (std::string(CurTime)/*t->getRetStr()*/);
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

