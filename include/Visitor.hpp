/*
 * Visitor.h
 *
 *  Created on: Apr 13, 2014
 *      Author: josephx
 *
 *      From: loki lib
 */

#ifndef VISITOR_H_
#define VISITOR_H_

#include <assert.h>

namespace dp
{
class BaseVisitor
{
public:
    virtual
    ~BaseVisitor() {}
};

template<class T, typename R = void, bool ConstVisitor = false>
class Visitor;

template<class T, typename R>
class Visitor<T, R, false>
{
public:
    virtual
    ~Visitor() {}
    virtual R
    Visit(T&) = 0;
};

template<class T, typename R>
class Visitor<T, R, true>
{
public:
    virtual
    ~Visitor() {}
    virtual R
    Visit(const T&) = 0;
};

template<typename R, class T>
struct DefaultCatchAll
{
    static R
    OnUnknownVisitor(
        T&,
        BaseVisitor&
        )
    {
        assert(0);
        return(R());
    }
};

template<
    typename R                               = void,
    template<typename, class> class CatchAll = DefaultCatchAll,
    bool ConstVisitable                      = false>
class BaseVisitable;

template<typename R,
    template<typename, class> class CatchAll>
class BaseVisitable<R, CatchAll, false>
{
public:
    typedef R ReturnType;
    virtual
    ~BaseVisitable() {}
    virtual ReturnType
    Accept(BaseVisitor&) = 0;
protected:
    template<class T>
    static ReturnType
    AcceptImpl(
        T&           visited,
        BaseVisitor& guest
        )
    {
        if (Visitor<T, R>* p = dynamic_cast<Visitor<T, R>*>(&guest))
            return(p->Visit(visited));
        return(CatchAll<R, T>::OnUnknownVisitor(visited, guest));
    }
};

template<typename R,
    template<typename, class> class CatchAll>
class BaseVisitable<R, CatchAll, true>
{
public:
    typedef R ReturnType;
    virtual
    ~BaseVisitable() {}
    virtual ReturnType
    Accept(BaseVisitor&) const = 0;
protected:
    template<class T>
    static ReturnType
    AcceptImpl(
        const T&     visited,
        BaseVisitor& guest
        )
    {
        if (Visitor<T, R, true>* p = dynamic_cast<Visitor<T, R, true>*>(&guest))
            return(p->Visit(visited));
        return(CatchAll<R, T>::OnUnknownVisitor(const_cast<T&>(visited), guest));
    }
};

#define VISITABLE() \
    virtual ReturnType Accept(dp::BaseVisitor & guest) \
    {return AcceptImpl(*this, guest); }

#define CONST_VISITABLE() \
    virtual ReturnType Accept(eutest::BaseVisitor & guest) const \
    {return AcceptImpl(*this, guest); }
} /* namespace eutest */

#endif /* VISITOR_H_ */
