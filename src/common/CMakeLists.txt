cmake_minimum_required(VERSION 3.14)

target_sources(${LIBRARY_COMMON}
  PUBLIC
    IType.hpp
    IOutput.hpp
    IObject.hpp
    IIdentifiable.hpp
    IDescriptable.hpp
    String.hpp
    Version.hpp

  PRIVATE
    Version.cpp
)

target_sources(${UNITTEST_COMMON}
  PRIVATE
  String.test.cpp
  Version.test.cpp
)
