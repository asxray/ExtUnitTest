#ifndef SINGLETON_HPP
#define SINGLETON_HPP

#include <boost/shared_ptr.hpp>
#include <boost/thread/locks.hpp>
#include <boost/thread/mutex.hpp>

template<typename T>
class singleton
{
public:
    static boost::shared_ptr<T>
    Instance()
    {
        static boost::mutex mux;
        if (0 == mInstance.get())
        {
            boost::lock_guard<boost::mutex> guard(mux);
            if (0 == mInstance.get())
                mInstance.reset(new T);
        }
        return(mInstance);
    }
protected:
    singleton() {}
    virtual
    ~singleton() {}
private:
    singleton(const singleton&);
    const singleton&
                                operator = (const singleton&);
    static boost::shared_ptr<T> mInstance;
};

template<typename T>
boost::shared_ptr<T>
singleton<T>::mInstance;

#endif
