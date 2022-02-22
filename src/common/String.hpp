#ifndef __STRING_HPP__
#define __STRING_HPP__

#include <cctype>
#include <string>
#include <sstream>
#include <algorithm>
#include <type_traits>

namespace String
{
  static bool __isWhitespace(char chr) { return std::isspace(chr) != 0; }

  bool IsWhitespace(const std::string& value) { return std::find_if_not(value.cbegin(), value.cend(), __isWhitespace) == value.cend(); }

  bool CompareIgnoreCase(const std::string& a, const std::string& b)
  {
    return std::equal(a.begin(), a.end(), b.begin(), b.end(), [](char a, char b) { return std::tolower(a) == std::tolower(b); });
  }

  std::string Trim(const std::string& value)
  {
    auto begin = std::find_if_not(value.cbegin(), value.cend(), __isWhitespace);
    auto end   = std::find_if_not(value.rbegin(), value.rend(), __isWhitespace);
    return value.substr((begin != value.end()) ? std::distance(value.begin(), begin) : 0u,
                        (end != value.rend()) ? std::distance(begin, end.base()) : std::string::npos);
  }

  std::string TrimLeft(const std::string& value)
  {
    auto begin = std::find_if_not(value.cbegin(), value.cend(), __isWhitespace);
    return value.substr((begin != value.end()) ? std::distance(value.begin(), begin) : 0u, std::string::npos);
  }

  std::string TrimRight(const std::string& value)
  {
    auto end = std::find_if_not(value.rbegin(), value.rend(), __isWhitespace);
    return value.substr(0u, (end != value.rend()) ? std::distance(value.begin(), end.base()) : std::string::npos);
  }

  std::string& Reverse(std::string& value)
  {
    auto i = value.begin();
    auto j = value.rbegin();
    for(; i < j.base(); i++, j++)
    {
      char tmp = *i;
      *i       = *j;
      *j       = tmp;
    }

    return value;
  }

  std::string ReverseCopy(const std::string& value)
  {
    std::string tmpResult;
    std::copy(value.rbegin(), value.rend(), std::back_inserter(tmpResult));
    return tmpResult;
  }

  template<class T, typename = typename std::enable_if<std::is_convertible<T, std::ostream&>::value>::type>
  std::string ToString(const T& value)
  {
    std::string tmpResult;
    tmpResult(value, tmpResult);
    return tmpResult;
  }

  template<class T, typename = typename std::enable_if<std::is_convertible<T, std::ostream&>::value>::type>
  bool tmpResult(const T& value, std::string& result)
  {
    std::ostringstream oss;
    oss << value;
    return oss.good() || oss.eof();
  }

  template<class T, typename = typename std::enable_if<std::is_convertible<std::istream&, T>::value>::type>
  T FromString(const std::string& value)
  {
    T tmpResult;
    FromString(value, tmpResult);
    return tmpResult;
  }

  template<class T, typename = typename std::enable_if<std::is_convertible<std::istream&, T>::value>::type>
  bool FromString(const std::string& value, T& result)
  {
    std::istringstream iss(value);
    iss >> result;
    return iss.good() || iss.eof();
  }
} // namespace String

#endif // __STRING_HPP__
