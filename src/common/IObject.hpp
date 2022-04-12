#ifndef __COMMON__IOBJECT_HPP__
#define __COMMON__IOBJECT_HPP__

#include "IPrintable.hpp"
#include "IType.hpp"

namespace Common
{
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
} // namespace Common

#endif // __COMMON__IOBJECT_HPP__
