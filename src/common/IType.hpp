#ifndef __ITYPE_HPP__
#define __ITYPE_HPP__

#include <typeinfo>

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

  template<class T>
  const T& AsReference() const
  {
    return dynamic_cast<const T&>(*this);
  }

  template<class T>
  T& AsReference()
  {
    return dynamic_cast<T&>(*this);
  }

  template<class T>
  const T* AsPointer() const
  {
    return dynamic_cast<const T*>(this);
  }

  template<class T>
  T* AsPointer()
  {
    return dynamic_cast<T*>(this);
  }

  virtual ~IType() = default;

  protected:
  IType() = default;

  private:
  IType(const IType&) = delete;
  IType& operator=(const IType&) = delete;
};

#endif // __ITYPE_HPP__
