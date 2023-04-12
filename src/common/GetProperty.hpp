#ifndef __COMMON__GETPROPERTY_HPP__
#define __COMMON__GETPROPERTY_HPP__

#include "PropertyBase.hpp"

namespace Common
{
  template<class T>
  class GetProperty : public PropertyBase<T>
  {
    public:
    operator const T&() const
    {
        return PropertyBase<T>::m_Object;
    }

    GetProperty(T& object) : PropertyBase<T>(object) {}
    virtual ~GetProperty() override = default;
  };
} // namespace Common

#endif // __COMMON__GETPROPERTY_HPP__
