#include "FullProperty.hpp"

#include <gtest/gtest.h>

using namespace ::testing;
using namespace Common;

namespace UnitTest
{
  TEST(FullProperty, Invoke)
  {
    int object = 54321;
    FullProperty<int> property(object);

    ASSERT_EQ(property, 54321);
    ASSERT_EQ(object, 54321);
    property = 12345;
    ASSERT_EQ(property, 12345);
    ASSERT_EQ(object, 12345);
  }
} // namespace UnitTest
