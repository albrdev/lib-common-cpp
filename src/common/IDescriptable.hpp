#ifndef __IDESCRIPTABLE_HPP__
#define __IDESCRIPTABLE_HPP__

#include <string>

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

#endif // __IDESCRIPTABLE_HPP__
