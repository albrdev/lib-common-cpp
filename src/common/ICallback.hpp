#ifndef __COMMON__ICALLBACK_HPP__
#define __COMMON__ICALLBACK_HPP__

namespace Common
{
  template<class T, class... TArgs>
  class ICallback
  {
    public:
    virtual T Invoke(TArgs... args) = 0;

    virtual ~ICallback() = default;

    protected:
    ICallback() = default;

    private:
    ICallback(const ICallback&) = delete;
    ICallback& operator=(const ICallback&) = delete;
  };
} // namespace Common

#endif // __COMMON__ICALLBACK_HPP__
