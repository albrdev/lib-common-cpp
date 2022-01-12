#ifndef __VERSION_HPP__
#define __VERSION_HPP__

#include <cstdint>
#include <string>
#include <ostream>
#include <istream>
#include <sstream>
#include "IOutput.hpp"

namespace Common
{
  class Version : IOutput
  {
    public:
    friend std::ostream& operator<<(std::ostream& stream, const Version& version) { return stream << version.ToString(); }

    friend std::istream& operator>>(std::istream& stream, Version& version)
    {
      stream >> version.m_Major;
      stream.ignore(1, '.');
      stream >> version.m_Minor;
      stream.ignore(1, '.');
      stream >> version.m_Build;
      return stream;
    }

    virtual std::string ToString() const override;
    void Read(std::istream& stream);
    void Read(const std::string& value);

    bool operator==(const Version& rhs);
    bool operator!=(const Version& rhs);

    bool operator>(const Version& rhs);
    bool operator<(const Version& rhs);

    bool operator>=(const Version& rhs);
    bool operator<=(const Version& rhs);

    Version operator+(const Version& rhs) const;
    Version operator-(const Version& rhs) const;

    Version operator<<(const Version& rhs) const;
    Version operator>>(const Version& rhs) const;

    Version& operator+=(const Version& rhs);
    Version& operator-=(const Version& rhs);

    std::uint32_t GetMajor() const;
    std::uint32_t GetMinor() const;
    std::uint32_t GetBuild() const;

    Version(std::uint32_t major, std::uint32_t minor, std::uint32_t build);
    virtual ~Version() override = default;

    Version();
    Version(const Version& other);
    Version(Version&& other);
    Version& operator=(const Version& other);
    Version& operator=(Version&& other);

    private:
    std::uint32_t m_Major;
    std::uint32_t m_Minor;
    std::uint32_t m_Build;
  };
} // namespace Common

#endif // __VERSION_HPP__
