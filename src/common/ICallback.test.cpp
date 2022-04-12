#include "ICallback.hpp"

#include <gtest/gtest.h>

using namespace ::testing;
using namespace Common;

namespace UnitTest
{
  class ICallbackImplA : public ICallback<void, int&>
  {
    public:
    virtual void Invoke(int& arg) override { arg = 12345; }

    ICallbackImplA()
        : ICallback()
    {}

    virtual ~ICallbackImplA() override = default;
  };

  class ICallbackImplB : public ICallback<int>
  {
    public:
    virtual int Invoke() override { return 12345; }

    ICallbackImplB()
        : ICallback()
    {}

    virtual ~ICallbackImplB() override = default;
  };

  class ICallbackImplC : public ICallback<int, int&, int&>
  {
    public:
    virtual int Invoke(int& arg1, int& arg2) override
    {
      arg1++;
      arg2--;
      return 12345;
    }

    ICallbackImplC()
        : ICallback()
    {}

    virtual ~ICallbackImplC() override = default;
  };

  TEST(ICallback, Invoke)
  {
    {
      ICallbackImplA instance;
      int arg = 0;

      instance.Invoke(arg);
      ASSERT_EQ(arg, 12345);
    }

    {
      ICallbackImplB instance;
      ASSERT_EQ(instance.Invoke(), 12345);
    }

    {
      ICallbackImplC instance;
      int arg1 = 0;
      int arg2 = 0;

      ASSERT_EQ(instance.Invoke(arg1, arg2), 12345);
      ASSERT_EQ(arg1, 1);
      ASSERT_EQ(arg2, -1);
    }
  }
} // namespace UnitTest
