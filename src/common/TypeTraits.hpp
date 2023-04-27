#ifndef __COMMON__TYPETRAITS_HPP__
#define __COMMON__TYPETRAITS_HPP__

#include <type_traits>

namespace Common
{
  template <class T, bool = std::is_enum<T>::value>
  struct safe_underlying_type {
      using type = typename std::underlying_type<T>::type;
  };

  template <class T>
  struct safe_underlying_type<T, false> {
      using type = T;
  };

  template<class T>
  using safe_underlying_type_t = typename safe_underlying_type<T>::type;
} // namespace Common

#endif // __COMMON__TYPETRAITS_HPP__
