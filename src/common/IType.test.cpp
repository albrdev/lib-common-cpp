#include <gtest/gtest.h>
#include "IType.hpp"
#include <typeinfo>

using namespace ::testing;
using namespace Common;

namespace UnitTest
{
  class ITypeImplA : public IType
  {};

  class ITypeImplB : public ITypeImplA
  {};

  TEST(IType, Basics)
  {
    ITypeImplA instanceA;
    ITypeImplA& rInstanceA = instanceA;

    ITypeImplB instanceB;
    ITypeImplA& rInstanceB = instanceB;

    ASSERT_EQ(instanceA.GetTypeInfo(), typeid(ITypeImplA));
    ASSERT_NE(instanceA.GetTypeInfo(), typeid(ITypeImplB));
    ASSERT_EQ(instanceB.GetTypeInfo(), typeid(ITypeImplB));
    ASSERT_NE(instanceB.GetTypeInfo(), typeid(ITypeImplA));

    ASSERT_NE(rInstanceB.AsPointer<ITypeImplB>(), nullptr);
    ASSERT_EQ(rInstanceA.AsPointer<ITypeImplB>(), nullptr);

    ASSERT_NO_THROW(rInstanceB.AsReference<ITypeImplB>());
    ASSERT_THROW(rInstanceA.AsReference<ITypeImplB>(), std::bad_cast);
  }
} // namespace UnitTest
