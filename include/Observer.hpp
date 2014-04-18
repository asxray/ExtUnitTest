/*
 * Observer.hpp
 *
 *  Created on: Apr 18, 2014
 *      Author: josephx
 */

#ifndef OBSERVER_HPP_
#define OBSERVER_HPP_

#include <list>
#include <memory>

namespace eutest
{
class BaseObserver
{
public:
    virtual
    ~BaseObserver() {}
};

template<class T>
class Observer
    : virtual public BaseObserver
{
public:
    virtual
    ~Observer() {}
    virtual void
    Update(const T& subject) = 0;
};

class Subject
{
public:
    virtual
    ~Subject() {}
    virtual void
    Attach(std::shared_ptr<BaseObserver> obs)
    {
        observers.push_back(obs);
    }
protected:
    std::list<std::shared_ptr<BaseObserver>> observers;
    virtual
    void
    Notify() const = 0;
    template<class T>
    void
    NotifyImpl(const T& subj) const
    {
        for (auto& sp : observers)
            if (auto* p = dynamic_cast<Observer<T>*>(sp.get()))
                p->Update(subj);
    }
};
#define NOTIFY() \
    virtual void Notify() const {NotifyImpl(*this); }
} /* namespace eutest */
#endif /* OBSERVER_HPP_ */
