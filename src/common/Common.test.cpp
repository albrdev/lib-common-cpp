#include "Common.hpp"

#include <functional>

#include <gtest/gtest.h>

using namespace ::testing;
using namespace Common;

namespace UnitTest
{
  static void func1() {}
  static void func2() {}

  TEST(Common, Basics)
  {
    {
      std::function<void()> a = nullptr;
      std::function<void()> b = nullptr;
      ASSERT_TRUE(CompareFunctions(a, b));
    }

    {
      std::function<void()> a = func1;
      std::function<void()> b = func1;
      ASSERT_TRUE(CompareFunctions(a, b));
    }

    {
      std::function<void()> a = func1;
      std::function<void()> b = func2;
      ASSERT_FALSE(CompareFunctions(a, b));
    }
  }
} // namespace UnitTest
