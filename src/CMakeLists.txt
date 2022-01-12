cmake_minimum_required(VERSION 3.14)

target_sources(${TARGET_MAIN}
  PUBLIC
    IType.hpp
    IOutput.hpp
    IObject.hpp
    IDescriptable.hpp
    Version.hpp

  PRIVATE
    Version.cpp
)

target_sources(${TARGET_TEST}
  PRIVATE
  Version.test.cpp
)
