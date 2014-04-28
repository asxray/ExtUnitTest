/*
 * Cloneable.h
 *
 *  Created on: Apr 16, 2014
 *      Author: josephx
 */

#ifndef CLONEABLE_HPP_
#define CLONEABLE_HPP_

namespace dp {
class Cloneable {
 public:
  virtual ~Cloneable() {}
  virtual Cloneable* clone(void) const = 0;
};

#define CLONE(X) \
  virtual X* clone(void) const { return new X(*this); }
} /* namespace eutest */

#endif /* CLONEABLE_H_ */
