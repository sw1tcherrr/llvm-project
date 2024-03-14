#include "LifeTargetInfo.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

Target& llvm::getTheLifeTarget() {
    static Target TheLifeTarget;
    return TheLifeTarget;
}

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeLifeTargetInfo() {
  RegisterTarget<Triple::life,/*HasJIT=*/true> X(getTheLifeTarget(), "life", "Life (64-bit little endian)", "Life");
}