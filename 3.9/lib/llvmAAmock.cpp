// llvmAAmock for llvm 3.9

#include "llvmAAmock.h"

#include "llvm/ADT/Statistic.h"
#include "llvm/IR/Module.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/CommandLine.h"

using namespace llvm;

cl::opt<bool> DumpDebugInfo("dump-debug", cl::desc("Dump debug info into stderr"), cl::init(false), cl::Hidden);
cl::opt<bool> DumpResultInfo("dump-result", cl::desc("Dump result info into stderr"), cl::init(false), cl::Hidden);
cl::opt<bool> DumpConstraintInfo("dump-cons", cl::desc("Dump constraint info into stderr"), cl::init(false), cl::Hidden);

llvmAAmock::llvmAAmock(const Module& module)
{
	run(module);
}



bool llvmAAmock::run(const Module &M)
{
	return false;
}


bool llvmAAmock::run(const Function &F)
{
	return false;
}



