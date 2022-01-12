#ifndef __IOBJECT_HPP__
#define __IOBJECT_HPP__

#include "IType.hpp"
#include "IPrintable.hpp"

class IObject : public IType, public IPrintable
{
  public:
  virtual ~IObject() override = default;

  protected:
  IObject() = default;

  private:
  IObject(const IObject&) = delete;
  IObject& operator=(const IObject&) = delete;
};

#endif // __IOBJECT_HPP__
