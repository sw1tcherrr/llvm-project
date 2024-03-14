add_llvm_component_library(LLVMLifeDesc
  LifeMCTargetDesc.cpp

  LINK_COMPONENTS
  MC
  Support
  LifeInfo

  ADD_TO_COMPONENT
  Life
 )