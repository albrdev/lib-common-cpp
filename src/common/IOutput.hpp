#ifndef __IOUTPUT_HPP__
#define __IOUTPUT_HPP__

#include <string>
#include <ostream>

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

#endif // __IOUTPUT_HPP__
