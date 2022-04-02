cmake_minimum_required(VERSION 3.14)

target_sources(${LIBRARY_COMMON}
  PUBLIC
  IEquals.hpp
  IType.hpp
  IOutput.hpp
  IObject.hpp
  IIdentifiable.hpp
  IDescriptable.hpp
  ICallback.hpp

  PRIVATE
)

target_sources(${UNITTEST_COMMON}
  PRIVATE
  IType.test.cpp
  ICallback.test.cpp
)
