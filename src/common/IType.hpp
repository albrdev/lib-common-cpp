#ifndef __COMMON__ITYPE_HPP__
#define __COMMON__ITYPE_HPP__

#include <typeinfo>
#include <type_traits>

namespace Common
{
  class IType
  {
    public:
    virtual const std::type_info& GetTypeInfo() const final { return typeid(*this); }

    template<class T>
    bool IsType() const
    {
      const T* tmp = dynamic_cast<const T*>(this);
      return tmp != nullptr;
    }

    template<class T, typename = typename std::enable_if<std::is_pointer<T>::value || std::is_reference<T>::value>::type>
    T As() const
    {
      if constexpr(std::is_pointer<T>::value)
      {
        return dynamic_cast<T>(this);
      }
      else if constexpr(std::is_reference<T>::value)
      {
        return dynamic_cast<T>(*this);
      }
    }

    template<class T, typename = typename std::enable_if<std::is_pointer<T>::value || std::is_reference<T>::value>::type>
    T As()
    {
      if constexpr(std::is_pointer<T>::value)
      {
        return dynamic_cast<T>(this);
      }
      else if constexpr(std::is_reference<T>::value)
      {
        return dynamic_cast<T>(*this);
      }
    }

    virtual ~IType() = default;

    protected:
    IType() = default;

    private:
    IType(const IType&) = delete;
    IType& operator=(const IType&) = delete;
  };
} // namespace Common

#endif // __COMMON__ITYPE_HPP__
