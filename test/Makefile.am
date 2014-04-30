include $(top_srcdir)/common.am

AM_DEFAULT_SOURCE_EXT = .cpp

AM_CXXFLAGS +=\
-D BOOST_TEST_DYN_LINK\
-D BOOST_TEST_MAIN\
-I $(top_srcdir)/src\
-I $(top_srcdir)/soci/src/core\
-I /usr/include/mysql/

AM_LDFLAGS=\
../src/libextunittest.la\
$(top_srcdir)/soci/src/lib/libsoci_core.a\
$(top_srcdir)/soci/src/lib/libsoci_mysql.a\
-lboost_system\
-lboost_thread\
-lboost_unit_test_framework\
-ldl\
-lmysqlclient

TESTS_ENVIRONMENT = valgrind -q
TESTS =\
BaseTestObserver_test\
BaseTestRunner_test\
Cloneable_test\
Composite_test\
ConsoleTestLogger_test\
DatabaseLog_test\
Observer_test\
RootTestSuite_test\
Singleton_test\
TestBody_test\
TestCase_test\
TestResource_test\
TestResult_test\
TestStatus_test\
TestSuite_test\
Visitor_test

check_PROGRAMS = $(TESTS)
