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

namespace dp
{
class BaseObserver
{
public:
    virtual
    ~BaseObserver() {}
};

// T is the subject to observe.
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
private:
    std::list<std::shared_ptr<BaseObserver> > observers;
public:
    virtual
    ~Subject() {}
    virtual void
    Attach(std::shared_ptr<BaseObserver> obs)
    {
        observers.push_back(obs);
    }
protected:
    virtual
    void
    Notify() const = 0;
    // T is an inherited class
    template<class T>
    void
    NotifyImpl(const T& subj) const
    {
        for (auto& sp : observers)
            if (auto* p = dynamic_cast<Observer<T>*>(sp.get()))
                p->Update(subj);
    }
};
// add this macor in the inherited subject class.
#define NOTIFY() \
    virtual void Notify() const {NotifyImpl(*this); }
} /* namespace eutest */
#endif /* OBSERVER_HPP_ */
