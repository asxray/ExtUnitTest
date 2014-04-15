#ifndef SINGLETON_HPP
#define SINGLETON_HPP

#include <boost/shared_ptr.hpp>

template<typename T>
class singleton
{
public:
    typedef T BaseType;
    static T&
    Instance()
    {
        if (0 == mInstance.get())
        {
#pragma omp critical
            if (0 == mInstance.get())
                mInstance.reset(new T);
        }
        return(*mInstance);
    }
private:
    static boost::shared_ptr<T> mInstance;
};

template<typename T>
boost::shared_ptr<T>
singleton<T>::mInstance;

#define SINGLETON() \
    friend BaseType& singleton<BaseType>::Instance(); \
    friend void boost::checked_delete<>(BaseType*); \
    const BaseType& \
    operator = (BaseType&);

#endif
