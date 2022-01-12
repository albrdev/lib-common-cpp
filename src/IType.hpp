#ifndef __ITYPE_HPP__
#define __ITYPE_HPP__

#include <typeinfo>

class IType
{
  public:
  virtual const std::type_info& GetType() const final { return typeid(*this); }

  virtual ~IType() = default;

  protected:
  IType() = default;

  private:
  IType(const IType&) = delete;
  IType& operator=(const IType&) = delete;
};

#endif // __ITYPE_HPP__
