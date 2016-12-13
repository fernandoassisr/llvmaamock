// llvmAAmock for llvm 3.9

#ifndef LLVMAAMOCKAA_H
#define LLVMAAMOCKAA_H

#include "llvmAAmock.h"

#include "llvm/Analysis/AliasAnalysis.h"
#include "llvm/Pass.h"


class llvmAAmockAAResult : public llvm::AAResultBase<llvmAAmockAAResult> {
private:
    friend llvm::AAResultBase<llvmAAmockAAResult>;

    //    llvmAAmock aamock;
    //    llvm::AliasResult llvmAAmockAAResult::mockAlias(const Value* v1, const Value* v2);

public:
    llvmAAmockAAResult(const llvm::Module&);
    llvmAAmockAAResult(const llvm::Function&);

    llvm::AliasResult alias(const llvm::MemoryLocation&,
                            const llvm::MemoryLocation&);
};

class llvmAAmockAAWrapperPass : public llvm::ModulePass {
private:
    std::unique_ptr<llvmAAmockAAResult> result;

public:
    static char ID;

    llvmAAmockAAWrapperPass();

    llvmAAmockAAResult& getResult() { return *result; }
    const llvmAAmockAAResult& getResult() const { return *result; }

    bool runOnModule(llvm::Module&) override;
    //    bool doFinalization(llvm::Module&) override;
    void getAnalysisUsage(llvm::AnalysisUsage& AU) const override;
};


class llvmAAmockAAFPWrapperPass : public llvm::FunctionPass {
private:
    std::unique_ptr<llvmAAmockAAResult> result;

public:
    static char ID;

    llvmAAmockAAFPWrapperPass();

    llvmAAmockAAResult& getResult() { return *result; }
    const llvmAAmockAAResult& getResult() const { return *result; }

    bool runOnFunction(llvm::Function&) override;
    void getAnalysisUsage(llvm::AnalysisUsage& AU) const override;
};

#endif
