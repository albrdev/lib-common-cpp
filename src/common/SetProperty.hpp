#ifndef __COMMON__SETPROPERTY_HPP__
#define __COMMON__SETPROPERTY_HPP__

#include "PropertyBase.hpp"

namespace Common
{
  template<class T>
  class SetProperty : public PropertyBase<T>
  {
    public:
    SetProperty<T>& operator=(const T& value)
    {
        PropertyBase<T>::m_Object = value;
        return *this;
    }

    SetProperty(T& object) : PropertyBase<T>(object) {}
    virtual ~SetProperty() override = default;
  };
} // namespace Common

#endif // __COMMON__SETPROPERTY_HPP__
