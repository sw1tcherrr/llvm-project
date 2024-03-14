#include "LifeTargetMachine.h"
#include "TargetInfo/LifeTargetInfo.h"
#include "llvm/MC/TargetRegistry.h"
#include <optional>

using namespace llvm;

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeLifeTarget() {
  RegisterTargetMachine<LifeTargetMachine> X(getTheLifeTarget());
}

static std::string getTheDataLayout() {
  return "e-m:e-p:64:64-i8:8:32-i16:16:32-i64:64-n32";
}

static Reloc::Model getEffectiveRelocModel(bool JIT, std::optional<Reloc::Model> RM) {
  if (!RM || JIT)
     return Reloc::Static;
  return *RM;
}

LifeTargetMachine::LifeTargetMachine(const Target &T, const Triple &TT,
                                     StringRef CPU, StringRef FS,
                                     const TargetOptions &Options,
                                     std::optional<Reloc::Model> RM,
                                     std::optional<CodeModel::Model> CM,
                                     CodeGenOptLevel OL, bool JIT)
    : LLVMTargetMachine(T, getTheDataLayout(), TT,
                        CPU, FS, Options, getEffectiveRelocModel(JIT, RM),
                        getEffectiveCodeModel(CM, CodeModel::Small), OL) {
    initAsmInfo();
}
