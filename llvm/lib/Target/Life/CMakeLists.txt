add_llvm_component_group(Life)

add_llvm_target(LifeCodeGen
  LifeTargetMachine.cpp

  LINK_COMPONENTS
  CodeGen
  Core
  Support
  Target
  LifeInfo

  ADD_TO_COMPONENT
  Life
  )

add_subdirectory(MCTargetDesc)
add_subdirectory(TargetInfo)