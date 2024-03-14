add_llvm_component_library(LLVMLifeInfo
  LifeTargetInfo.cpp

  LINK_COMPONENTS
  MC
  Support

  ADD_TO_COMPONENT
  Life
  )