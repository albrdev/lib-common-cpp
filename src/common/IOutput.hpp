#ifndef __COMMON__IOUTPUT_HPP__
#define __COMMON__IOUTPUT_HPP__

#include <string>
#include <ostream>

namespace Common
{
  class IOutput
  {
    public:
    friend std::ostream& operator<<(std::ostream& stream, const IOutput& object);

    virtual std::string ToString() const { return typeid(*this).name(); }

    virtual ~IOutput() = default;

    protected:
    IOutput() = default;

    private:
    IOutput(const IOutput&) = delete;
    IOutput& operator=(const IOutput&) = delete;
  };

  inline std::ostream& operator<<(std::ostream& stream, const IOutput& object) { return stream << object.ToString(); }
} // namespace Common

#endif // __COMMON__IOUTPUT_HPP__
