// llvmAAmock for llvm 3.9

#include "llvmAAmockAA.h"

#include "llvm/IR/Module.h"

using namespace llvm;

#include <stdio.h>

llvm::AliasResult llvmAAmockAAResult::alias(const MemoryLocation& l1,
                                    const MemoryLocation& l2) {
    return MustAlias;
}

llvmAAmockAAResult::llvmAAmockAAResult(const Module& m) {}


void llvmAAmockAAWrapperPass::getAnalysisUsage(AnalysisUsage& AU) const {
    AU.setPreservesAll();
}

bool llvmAAmockAAWrapperPass::runOnModule(Module& m) {
    result.reset(new llvmAAmockAAResult(m));

    printf("llvmAAmockAAWrapperPass::runOnModule\n");
    return false;
}

llvmAAmockAAWrapperPass::llvmAAmockAAWrapperPass() : ModulePass(ID) {}

char llvmAAmockAAWrapperPass::ID = 0;
static RegisterPass<llvmAAmockAAWrapperPass>
    XM("llvmaamock", "llvmAAmock Alias Analysis", true, true);
// static RegisterAnalysisGroup<AliasAnalysis> Y(X);



// llvmAAmock for llvm 3.9

#include "llvm/IR/Function.h"

llvmAAmockAAResult::llvmAAmockAAResult(const Function& f) {}

void llvmAAmockAAFPWrapperPass::getAnalysisUsage(AnalysisUsage& AU) const {
    AU.setPreservesAll();
}

bool llvmAAmockAAFPWrapperPass::runOnFunction(Function& f) {
    result.reset(new llvmAAmockAAResult(f));

    printf("llvmAAmockAAFPWrapperPass::runOnFunction\n");
    return false;
}

llvmAAmockAAFPWrapperPass::llvmAAmockAAFPWrapperPass() : FunctionPass(ID) {}

char llvmAAmockAAFPWrapperPass::ID = 0;
static RegisterPass<llvmAAmockAAFPWrapperPass>
    XF("llvmaamockfp", "llvmAAmock Alias Analysis", true, true);
// static RegisterAnalysisGroup<AliasAnalysis> Y(X);
