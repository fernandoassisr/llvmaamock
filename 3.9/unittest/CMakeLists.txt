add_subdirectory (googletest)

include_directories(
  ${llvmAAmock_SOURCE_DIR}/unittest/googletest/include
  ${llvmAAmock_SOURCE_DIR}/include)

link_directories (${llvmAAmock_BINARY_DIR}/lib)

set (EXECUTABLE_OUTPUT_PATH ${llvmAAmock_BINARY_DIR}/unittest)
add_definitions(-DGTEST_HAS_RTTI=1)

add_executable(llvmAAmockTest llvmAAmockTest.cpp)
target_link_libraries(llvmAAmockTest LLVMAsmParser LLVMCore LLVMSupport llvmAAmockStatic gtest_main)