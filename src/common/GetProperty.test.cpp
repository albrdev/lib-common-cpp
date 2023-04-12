#include "GetProperty.hpp"

#include <gtest/gtest.h>

using namespace ::testing;
using namespace Common;

namespace UnitTest
{
  TEST(GetProperty, Invoke)
  {
    int object = 54321;
    GetProperty<int> property(object);

    ASSERT_EQ(property, 54321);
    ASSERT_EQ(object, 54321);
    object = 12345;
    ASSERT_EQ(property, 12345);
    ASSERT_EQ(object, 12345);
  }
} // namespace UnitTest
