include $(top_srcdir)/common.am

# AM_LDADD = $(top_srcdir)/src/libextunittest.la
AM_DEFAULT_SOURCE_EXT = .cpp
AM_CXXFLAGS += -D BOOST_TEST_DYN_LINK

noinst_PROGRAMS = testall.out

testall_out_LDADD = $(top_srcdir)/src/libextunittest.la\
	/usr/lib/x86_64-linux-gnu/libboost_unit_test_framework.so

testall_out_SOURCES = \
	main.cpp\
	Composite_test.cpp\
	Observer_test.cpp\
	Singleton_test.cpp\
	TestStatus_test.cpp\
	Visitor_test.cpp
