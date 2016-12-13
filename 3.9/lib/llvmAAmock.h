// llvmAAmock for llvm 3.9

#ifndef LLVMAAMOCK_H
#define LLVMAAMOCK_H

#include "llvm/IR/DataLayout.h"
#include "llvm/IR/CallSite.h"
#include "llvm/ADT/DenseMap.h"

#include <vector>

class llvmAAmock
{
public:
	static char ID;

	llvmAAmock(const llvm::Module&);
	bool run(const llvm::Module& M);
	bool run(const llvm::Function& F);

	friend class llvmAAmockAAResult;
};

#endif
