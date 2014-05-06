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

namespace dp {
class BaseObserver {
 public:
  virtual ~BaseObserver() {}
};

// T is the subject to observe.
template <class T>
class Observer : virtual public BaseObserver {
 public:
  virtual ~Observer() {}
  virtual void Update(T const* const subject) = 0;
};

class Subject {
 private:
  std::list<BaseObserver*> observers;

 public:
  virtual ~Subject() {}
  virtual void Attach(BaseObserver* obs) { observers.push_back(obs); }

 protected:
  virtual void Notify() const = 0;
  // T is an inherited class
  template <class T>
  void NotifyImpl(T const* const subj) const {
    for (auto& obs : observers)
      if (auto* po = dynamic_cast<Observer<T>*>(obs)) po->Update(subj);
  }
};
// add this macor in the inherited subject class.
#define NOTIFY() \
  virtual void Notify() const { NotifyImpl(this); }
} /* namespace eutest */
#endif /* OBSERVER_HPP_ */
