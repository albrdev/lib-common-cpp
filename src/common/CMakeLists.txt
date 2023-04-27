cmake_minimum_required(VERSION 3.14)

target_sources(${LIBRARY_COMMON}
  PUBLIC
  TypeTraits.hpp
  Common.hpp
  IEquals.hpp
  IType.hpp
  IOutput.hpp
  IObject.hpp
  IIdentifiable.hpp
  IDescriptable.hpp
  ICallback.hpp
  PropertyBase.hpp
  GetProperty.hpp
  SetProperty.hpp
  FullProperty.hpp

  PRIVATE
)

target_sources(${UNITTEST_COMMON}
  PRIVATE
  Common.test.cpp
  IType.test.cpp
  ICallback.test.cpp
  GetProperty.test.cpp
  SetProperty.test.cpp
  FullProperty.test.cpp
)
