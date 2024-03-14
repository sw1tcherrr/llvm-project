#pragma once

#include "llvm/Target/TargetMachine.h"

namespace llvm {

class LifeTargetMachine : public LLVMTargetMachine {
public:
  LifeTargetMachine(const Target &T, const Triple &TT, StringRef CPU,
                    StringRef FS, const TargetOptions &Options,
                    std::optional<Reloc::Model> RM,
                    std::optional<CodeModel::Model> CM, CodeGenOptLevel OL,
                    bool JIT);
};

} // namespace llvm
