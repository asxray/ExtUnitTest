#ifndef SINGLETON_HPP
#define SINGLETON_HPP

#include <boost/shared_ptr.hpp>
namespace dp {
template <typename T>
class Singleton {
 public:
  static T& Instance() {
    if (0 == mInstance.get()) {
#pragma omp critical
      if (0 == mInstance.get()) mInstance.reset(new T);
    }
    return (*mInstance);
  }

 protected:
  typedef T BaseType;
  Singleton() {}
  Singleton(Singleton&) {}
  virtual ~Singleton() {}
  const Singleton& operator=(Singleton&) {}

 private:
  static boost::shared_ptr<T> mInstance;
};

template <typename T>
boost::shared_ptr<T> Singleton<T>::mInstance;

#define SINGLETON(tt)                               \
  \
private:                                            \
  tt();                                             \
  tt(tt&);                                          \
  virtual ~tt();                                    \
  friend BaseType& Singleton<BaseType>::Instance(); \
  friend void boost::checked_delete<>(tt*);   \
  const BaseType& operator=(BaseType&)
}
#endif
