#ifndef __COMMON__FULLPROPERTY_HPP__
#define __COMMON__FULLPROPERTY_HPP__

#include "GetProperty.hpp"
#include "SetProperty.hpp"

namespace Common
{
  template<class T>
  class FullProperty : public virtual GetProperty<T>, public virtual SetProperty<T>
  {
    public:
    using SetProperty<T>::operator=;

    FullProperty(T& object) : GetProperty<T>(object), SetProperty<T>(object) {}
    virtual ~FullProperty() override = default;
  };
} // namespace Common

#endif // __COMMON__FULLPROPERTY_HPP__
