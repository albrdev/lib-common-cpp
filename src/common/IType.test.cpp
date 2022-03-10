#include <gtest/gtest.h>
#include "IType.hpp"
#include <typeinfo>

using namespace ::testing;
using namespace Common;

namespace UnitTest
{
  class ITypeImplA : public IType
  {
    public:
    ITypeImplA()
        : IType()
    {}

    virtual ~ITypeImplA() override = default;
  };

  class ITypeImplB : public ITypeImplA
  {
    public:
    ITypeImplB()
        : ITypeImplA()
    {}

    virtual ~ITypeImplB() override = default;
  };

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

    ASSERT_NE(rInstanceB.As<ITypeImplB*>(), nullptr);
    ASSERT_EQ(rInstanceB.As<ITypeImplB*>(), &instanceB);
    ASSERT_EQ(rInstanceA.As<ITypeImplB*>(), nullptr);

    ASSERT_NO_THROW(rInstanceB.As<ITypeImplB&>());
    ASSERT_EQ(&rInstanceB.As<ITypeImplB&>(), &instanceB);
    ASSERT_THROW(rInstanceA.As<ITypeImplB&>(), std::bad_cast);
  }
} // namespace UnitTest
