#include "Singleton.hpp"

class testSingleton
    : public singleton<testSingleton>
{
protected:
    friend class singleton<testSingleton>;
    friend void boost::checked_delete<
        >(testSingleton*);
    testSingleton() {}
    virtual
    ~testSingleton() {}
    testSingleton(testSingleton&) {}
    const testSingleton&
    operator = (testSingleton&);
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
    testSingleton::Instance()->say();
}
