/*
 * Cloneable.h
 *
 *  Created on: Apr 16, 2014
 *      Author: josephx
 */

#ifndef CLONEABLE_H_
#define CLONEABLE_H_

namespace eutest
{
class Cloneable
{
public:
    virtual
    ~Cloneable() {}
    virtual Cloneable*
    clone(void) const = 0;
};

#define CLONEABLE(X) \
    virtual X * clone(void) const {return new X(*this); }
}     /* namespace eutest */

#endif /* CLONEABLE_H_ */
