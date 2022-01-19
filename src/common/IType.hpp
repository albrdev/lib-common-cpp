#ifndef __ITYPE_HPP__
#define __ITYPE_HPP__

#include <typeinfo>

class IType
{
  public:
  virtual const std::type_info& GetType() const final { return typeid(*this); }

  template<class T>
  bool IsType() const
  {
    const T* tmp = dynamic_cast<const T*>(this);
    return tmp != nullptr;
  }

  template<class T>
  const T* AsType() const
  {
    return dynamic_cast<const T*>(this);
  }

  template<class T>
  T* AsType()
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
