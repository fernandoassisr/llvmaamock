# llvmaamock
llvm alias analysis pass mock

== Commandline
```
opt -load ./lib/libllvmAAmock.so -debug-pass=Structure -llvmaamock -llvmaamockfp -basicaa test.ll 
```

== Expected Output

```
Pass Arguments:  -targetlibinfo -tti -assumption-cache-tracker -llvmaamock -llvmaamockfp -domtree -basicaa -verify
Target Library Information
Target Transform Information
Assumption Cache Tracker
  ModulePass Manager
    llvmAAmock Alias Analysis
    FunctionPass Manager
      llvmAAmock Alias Analysis
      Dominator Tree Construction
      Basic Alias Analysis (stateless AA impl)
      Module Verifier
llvmAAmockAAWrapperPass::runOnModule
llvmAAmockAAFPWrapperPass::runOnFunction
```
