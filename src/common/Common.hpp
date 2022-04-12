#ifndef __COMMON__COMMON_HPP__
#define __COMMON__COMMON_HPP__

#include <functional>

namespace Common
{
  template<typename T, typename... U>
  bool CompareFunctions(std::function<T(U...)> a, std::function<T(U...)> b)
  {
    if(!a || !b)
    {
      return (!a) && (!b);
    }

    using type    = T(U...);
    type** rawLhs = a.template target<type*>();
    type** rawRhs = b.template target<type*>();
    return (*rawLhs) == (*rawRhs);
  }
} // namespace Common

#endif // __COMMON__COMMON_HPP__
