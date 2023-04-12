#ifndef __COMMON__PROPERTYBASE_HPP__
#define __COMMON__PROPERTYBASE_HPP__

namespace Common
{
  template<class T>
  class PropertyBase
  {
    public:
    virtual ~PropertyBase() = default;

    protected:
    T& m_Object;

    PropertyBase(T& object) : m_Object(object) {}
  };
} // namespace Common

#endif // __COMMON__PROPERTYBASE_HPP__
