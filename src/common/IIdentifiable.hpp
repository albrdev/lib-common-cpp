#ifndef __COMMON__IIDENTIFIABLE_HPP__
#define __COMMON__IIDENTIFIABLE_HPP__

namespace Common
{
  template<class T>
  class IIdentifiable
  {
    public:
    virtual const T& GetIdentifier() const = 0;

    virtual ~IIdentifiable() = default;

    protected:
    IIdentifiable() = default;

    private:
    IIdentifiable(const IIdentifiable&)            = delete;
    IIdentifiable& operator=(const IIdentifiable&) = delete;
  };
} // namespace Common

#endif // __COMMON__IIDENTIFIABLE_HPP__
