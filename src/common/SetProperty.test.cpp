#include "SetProperty.hpp"

#include <gtest/gtest.h>

using namespace ::testing;
using namespace Common;

namespace UnitTest
{
  TEST(SetProperty, Invoke)
  {
    int object = 54321;
    SetProperty<int> property(object);

    ASSERT_EQ(object, 54321);
    property = 12345;
    ASSERT_EQ(object, 12345);
  }
} // namespace UnitTest
