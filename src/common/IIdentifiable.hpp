#ifndef __IIDENTIFIABLE_HPP__
#define __IIDENTIFIABLE_HPP__

template<class T>
class IIdentifiable
{
  public:
  virtual const T& GetIdentifier() const = 0;

  virtual ~IIdentifiable() = default;

  protected:
  IIdentifiable() = default;

  private:
  IIdentifiable(const IIdentifiable&) = delete;
  IIdentifiable& operator=(const IIdentifiable&) = delete;
};

#endif // __IIDENTIFIABLE_HPP__
