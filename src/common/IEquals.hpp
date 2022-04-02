#ifndef __COMMON__IEQUALS_HPP__
#define __COMMON__IEQUALS_HPP__

namespace Common
{
  class IEquals
  {
    public:
    virtual bool Equals(const IEquals& other) const = 0;

    virtual ~IEquals() = default;

    protected:
    IEquals() = default;

    private:
    IEquals(const IEquals&) = delete;
    IEquals& operator=(const IEquals&) = delete;
  };
} // namespace Common

#endif // __COMMON__IEQUALS_HPP__
