include_directories (${llvmAAmock_SOURCE_DIR}/include)

set (llvmAAmockSourceCodes
  llvmAAmock.cpp
  llvmAAmockAA.cpp
)
add_library (llvmAAmockObj OBJECT ${llvmAAmockSourceCodes})
add_library (llvmAAmock SHARED $<TARGET_OBJECTS:llvmAAmockObj>)
add_library (llvmAAmockStatic STATIC $<TARGET_OBJECTS:llvmAAmockObj>)
target_link_libraries (llvmAAmockStatic LLVMCore LLVMSupport)