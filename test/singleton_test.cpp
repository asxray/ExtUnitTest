#include "Singleton.hpp"

class testSingleton
    : public singleton<testSingleton>
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

int
main()
{
    //	testSingleton ats; // can't compile
    //	ats.say();
    testSingleton::Instance().say();
}
