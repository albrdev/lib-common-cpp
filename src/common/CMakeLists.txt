cmake_minimum_required(VERSION 3.14)

target_sources(${LIBRARY_COMMON}
  PUBLIC
    IType.hpp
    IOutput.hpp
    IObject.hpp
    IDescriptable.hpp
    Version.hpp

  PRIVATE
    Version.cpp
)

target_sources(${UNITTEST_COMMON}
  PRIVATE
  Version.test.cpp
)
