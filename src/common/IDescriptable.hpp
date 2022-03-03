#ifndef __COMMON__IDESCRIPTABLE_HPP__
#define __COMMON__IDESCRIPTABLE_HPP__

#include <string>

namespace Common
{
  class IDescriptable
  {
    public:
    virtual std::string GetName()        = 0;
    virtual std::string GetDescription() = 0;

    virtual ~IDescriptable() = default;

    protected:
    IDescriptable() = default;

    private:
    IDescriptable(const IDescriptable&) = delete;
    IDescriptable& operator=(const IDescriptable&) = delete;
  };
} // namespace Common

#endif // __COMMON__IDESCRIPTABLE_HPP__
