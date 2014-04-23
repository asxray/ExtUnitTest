#include "Singleton.hpp"
#include <boost/test/unit_test.hpp>

class testSingleton
    : public dp::Singleton<testSingleton>
{
private:
    SINGLETON();
    testSingleton() {}
    testSingleton(testSingleton&) {}
    virtual
    ~testSingleton() {}
public:
    void
    say()
    {
        std::cout << "hello" << std::endl;
    }
};

BOOST_AUTO_TEST_CASE(singleton)
{
    //	testSingleton ats; // can't compile
    //	ats.say();
    testSingleton::Instance().say();
}
