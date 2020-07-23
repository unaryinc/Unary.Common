#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "clangBasic" for configuration "Release"
set_property(TARGET clangBasic APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(clangBasic PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libclangBasic.dll.a"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "LLVM"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/clangBasic.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS clangBasic )
list(APPEND _IMPORT_CHECK_FILES_FOR_clangBasic "${_IMPORT_PREFIX}/lib/libclangBasic.dll.a" "${_IMPORT_PREFIX}/bin/clangBasic.dll" )

# Import target "clangLex" for configuration "Release"
set_property(TARGET clangLex APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(clangLex PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libclangLex.dll.a"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "clangBasic;LLVM"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/clangLex.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS clangLex )
list(APPEND _IMPORT_CHECK_FILES_FOR_clangLex "${_IMPORT_PREFIX}/lib/libclangLex.dll.a" "${_IMPORT_PREFIX}/bin/clangLex.dll" )

# Import target "clangParse" for configuration "Release"
set_property(TARGET clangParse APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(clangParse PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libclangParse.dll.a"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "clangAST;clangBasic;clangLex;clangSema;LLVM"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/clangParse.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS clangParse )
list(APPEND _IMPORT_CHECK_FILES_FOR_clangParse "${_IMPORT_PREFIX}/lib/libclangParse.dll.a" "${_IMPORT_PREFIX}/bin/clangParse.dll" )

# Import target "clangAST" for configuration "Release"
set_property(TARGET clangAST APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(clangAST PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libclangAST.dll.a"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "clangBasic;clangLex;LLVM"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/clangAST.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS clangAST )
list(APPEND _IMPORT_CHECK_FILES_FOR_clangAST "${_IMPORT_PREFIX}/lib/libclangAST.dll.a" "${_IMPORT_PREFIX}/bin/clangAST.dll" )

# Import target "clangDynamicASTMatchers" for configuration "Release"
set_property(TARGET clangDynamicASTMatchers APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(clangDynamicASTMatchers PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libclangDynamicASTMatchers.dll.a"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "clangAST;clangASTMatchers;clangBasic;LLVM"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/clangDynamicASTMatchers.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS clangDynamicASTMatchers )
list(APPEND _IMPORT_CHECK_FILES_FOR_clangDynamicASTMatchers "${_IMPORT_PREFIX}/lib/libclangDynamicASTMatchers.dll.a" "${_IMPORT_PREFIX}/bin/clangDynamicASTMatchers.dll" )

# Import target "clangASTMatchers" for configuration "Release"
set_property(TARGET clangASTMatchers APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(clangASTMatchers PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libclangASTMatchers.dll.a"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "clangAST;clangBasic;LLVM"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/clangASTMatchers.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS clangASTMatchers )
list(APPEND _IMPORT_CHECK_FILES_FOR_clangASTMatchers "${_IMPORT_PREFIX}/lib/libclangASTMatchers.dll.a" "${_IMPORT_PREFIX}/bin/clangASTMatchers.dll" )

# Import target "clangCrossTU" for configuration "Release"
set_property(TARGET clangCrossTU APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(clangCrossTU PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libclangCrossTU.dll.a"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "clangAST;clangBasic;clangFrontend;clangIndex;LLVM"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/clangCrossTU.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS clangCrossTU )
list(APPEND _IMPORT_CHECK_FILES_FOR_clangCrossTU "${_IMPORT_PREFIX}/lib/libclangCrossTU.dll.a" "${_IMPORT_PREFIX}/bin/clangCrossTU.dll" )

# Import target "clangSema" for configuration "Release"
set_property(TARGET clangSema APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(clangSema PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libclangSema.dll.a"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "clangAST;clangAnalysis;clangBasic;clangEdit;clangLex;LLVM"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/clangSema.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS clangSema )
list(APPEND _IMPORT_CHECK_FILES_FOR_clangSema "${_IMPORT_PREFIX}/lib/libclangSema.dll.a" "${_IMPORT_PREFIX}/bin/clangSema.dll" )

# Import target "clangCodeGen" for configuration "Release"
set_property(TARGET clangCodeGen APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(clangCodeGen PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libclangCodeGen.dll.a"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "clangAnalysis;clangAST;clangASTMatchers;clangBasic;clangFrontend;clangLex;clangSerialization;LLVM"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/clangCodeGen.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS clangCodeGen )
list(APPEND _IMPORT_CHECK_FILES_FOR_clangCodeGen "${_IMPORT_PREFIX}/lib/libclangCodeGen.dll.a" "${_IMPORT_PREFIX}/bin/clangCodeGen.dll" )

# Import target "clangAnalysis" for configuration "Release"
set_property(TARGET clangAnalysis APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(clangAnalysis PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libclangAnalysis.dll.a"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "clangAST;clangASTMatchers;clangBasic;clangLex;LLVM"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/clangAnalysis.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS clangAnalysis )
list(APPEND _IMPORT_CHECK_FILES_FOR_clangAnalysis "${_IMPORT_PREFIX}/lib/libclangAnalysis.dll.a" "${_IMPORT_PREFIX}/bin/clangAnalysis.dll" )

# Import target "clangEdit" for configuration "Release"
set_property(TARGET clangEdit APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(clangEdit PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libclangEdit.dll.a"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "clangAST;clangBasic;clangLex;LLVM"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/clangEdit.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS clangEdit )
list(APPEND _IMPORT_CHECK_FILES_FOR_clangEdit "${_IMPORT_PREFIX}/lib/libclangEdit.dll.a" "${_IMPORT_PREFIX}/bin/clangEdit.dll" )

# Import target "clangRewrite" for configuration "Release"
set_property(TARGET clangRewrite APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(clangRewrite PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libclangRewrite.dll.a"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "clangBasic;clangLex;LLVM"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/clangRewrite.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS clangRewrite )
list(APPEND _IMPORT_CHECK_FILES_FOR_clangRewrite "${_IMPORT_PREFIX}/lib/libclangRewrite.dll.a" "${_IMPORT_PREFIX}/bin/clangRewrite.dll" )

# Import target "clangARCMigrate" for configuration "Release"
set_property(TARGET clangARCMigrate APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(clangARCMigrate PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libclangARCMigrate.dll.a"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "clangAST;clangAnalysis;clangBasic;clangEdit;clangFrontend;clangLex;clangRewrite;clangSema;clangSerialization;LLVM"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/clangARCMigrate.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS clangARCMigrate )
list(APPEND _IMPORT_CHECK_FILES_FOR_clangARCMigrate "${_IMPORT_PREFIX}/lib/libclangARCMigrate.dll.a" "${_IMPORT_PREFIX}/bin/clangARCMigrate.dll" )

# Import target "clangDriver" for configuration "Release"
set_property(TARGET clangDriver APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(clangDriver PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libclangDriver.dll.a"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "clangBasic;LLVM"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/clangDriver.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS clangDriver )
list(APPEND _IMPORT_CHECK_FILES_FOR_clangDriver "${_IMPORT_PREFIX}/lib/libclangDriver.dll.a" "${_IMPORT_PREFIX}/bin/clangDriver.dll" )

# Import target "clangSerialization" for configuration "Release"
set_property(TARGET clangSerialization APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(clangSerialization PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libclangSerialization.dll.a"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "clangAST;clangBasic;clangLex;clangSema;LLVM"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/clangSerialization.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS clangSerialization )
list(APPEND _IMPORT_CHECK_FILES_FOR_clangSerialization "${_IMPORT_PREFIX}/lib/libclangSerialization.dll.a" "${_IMPORT_PREFIX}/bin/clangSerialization.dll" )

# Import target "clangRewriteFrontend" for configuration "Release"
set_property(TARGET clangRewriteFrontend APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(clangRewriteFrontend PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libclangRewriteFrontend.dll.a"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "clangAST;clangBasic;clangEdit;clangFrontend;clangLex;clangRewrite;clangSerialization;LLVM"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/clangRewriteFrontend.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS clangRewriteFrontend )
list(APPEND _IMPORT_CHECK_FILES_FOR_clangRewriteFrontend "${_IMPORT_PREFIX}/lib/libclangRewriteFrontend.dll.a" "${_IMPORT_PREFIX}/bin/clangRewriteFrontend.dll" )

# Import target "clangFrontend" for configuration "Release"
set_property(TARGET clangFrontend APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(clangFrontend PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libclangFrontend.dll.a"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "clangAST;clangBasic;clangDriver;clangEdit;clangLex;clangParse;clangSema;clangSerialization;LLVM"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/clangFrontend.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS clangFrontend )
list(APPEND _IMPORT_CHECK_FILES_FOR_clangFrontend "${_IMPORT_PREFIX}/lib/libclangFrontend.dll.a" "${_IMPORT_PREFIX}/bin/clangFrontend.dll" )

# Import target "clangFrontendTool" for configuration "Release"
set_property(TARGET clangFrontendTool APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(clangFrontendTool PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libclangFrontendTool.dll.a"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "clangBasic;clangCodeGen;clangDriver;clangFrontend;clangRewriteFrontend;clangARCMigrate;clangStaticAnalyzerFrontend;LLVM"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/clangFrontendTool.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS clangFrontendTool )
list(APPEND _IMPORT_CHECK_FILES_FOR_clangFrontendTool "${_IMPORT_PREFIX}/lib/libclangFrontendTool.dll.a" "${_IMPORT_PREFIX}/bin/clangFrontendTool.dll" )

# Import target "clangToolingCore" for configuration "Release"
set_property(TARGET clangToolingCore APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(clangToolingCore PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libclangToolingCore.dll.a"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "clangAST;clangBasic;clangLex;clangRewrite;LLVM"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/clangToolingCore.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS clangToolingCore )
list(APPEND _IMPORT_CHECK_FILES_FOR_clangToolingCore "${_IMPORT_PREFIX}/lib/libclangToolingCore.dll.a" "${_IMPORT_PREFIX}/bin/clangToolingCore.dll" )

# Import target "clangToolingInclusions" for configuration "Release"
set_property(TARGET clangToolingInclusions APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(clangToolingInclusions PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libclangToolingInclusions.dll.a"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "clangBasic;clangLex;clangRewrite;clangToolingCore;LLVM"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/clangToolingInclusions.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS clangToolingInclusions )
list(APPEND _IMPORT_CHECK_FILES_FOR_clangToolingInclusions "${_IMPORT_PREFIX}/lib/libclangToolingInclusions.dll.a" "${_IMPORT_PREFIX}/bin/clangToolingInclusions.dll" )

# Import target "clangToolingRefactoring" for configuration "Release"
set_property(TARGET clangToolingRefactoring APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(clangToolingRefactoring PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libclangToolingRefactoring.dll.a"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "clangAST;clangASTMatchers;clangBasic;clangFormat;clangIndex;clangLex;clangRewrite;clangToolingCore;LLVM"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/clangToolingRefactoring.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS clangToolingRefactoring )
list(APPEND _IMPORT_CHECK_FILES_FOR_clangToolingRefactoring "${_IMPORT_PREFIX}/lib/libclangToolingRefactoring.dll.a" "${_IMPORT_PREFIX}/bin/clangToolingRefactoring.dll" )

# Import target "clangToolingASTDiff" for configuration "Release"
set_property(TARGET clangToolingASTDiff APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(clangToolingASTDiff PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libclangToolingASTDiff.dll.a"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "clangBasic;clangAST;clangLex;LLVM"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/clangToolingASTDiff.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS clangToolingASTDiff )
list(APPEND _IMPORT_CHECK_FILES_FOR_clangToolingASTDiff "${_IMPORT_PREFIX}/lib/libclangToolingASTDiff.dll.a" "${_IMPORT_PREFIX}/bin/clangToolingASTDiff.dll" )

# Import target "clangToolingSyntax" for configuration "Release"
set_property(TARGET clangToolingSyntax APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(clangToolingSyntax PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libclangToolingSyntax.dll.a"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "clangAST;clangBasic;clangFrontend;clangLex;clangToolingCore;LLVM"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/clangToolingSyntax.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS clangToolingSyntax )
list(APPEND _IMPORT_CHECK_FILES_FOR_clangToolingSyntax "${_IMPORT_PREFIX}/lib/libclangToolingSyntax.dll.a" "${_IMPORT_PREFIX}/bin/clangToolingSyntax.dll" )

# Import target "clangDependencyScanning" for configuration "Release"
set_property(TARGET clangDependencyScanning APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(clangDependencyScanning PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libclangDependencyScanning.dll.a"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "clangAST;clangBasic;clangDriver;clangFrontend;clangFrontendTool;clangLex;clangParse;clangSerialization;clangTooling;LLVM"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/clangDependencyScanning.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS clangDependencyScanning )
list(APPEND _IMPORT_CHECK_FILES_FOR_clangDependencyScanning "${_IMPORT_PREFIX}/lib/libclangDependencyScanning.dll.a" "${_IMPORT_PREFIX}/bin/clangDependencyScanning.dll" )

# Import target "clangTransformer" for configuration "Release"
set_property(TARGET clangTransformer APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(clangTransformer PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libclangTransformer.dll.a"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "clangAST;clangASTMatchers;clangBasic;clangLex;clangToolingCore;clangToolingRefactoring;LLVM"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/clangTransformer.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS clangTransformer )
list(APPEND _IMPORT_CHECK_FILES_FOR_clangTransformer "${_IMPORT_PREFIX}/lib/libclangTransformer.dll.a" "${_IMPORT_PREFIX}/bin/clangTransformer.dll" )

# Import target "clangTooling" for configuration "Release"
set_property(TARGET clangTooling APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(clangTooling PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libclangTooling.dll.a"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "clangAST;clangASTMatchers;clangBasic;clangDriver;clangFormat;clangFrontend;clangLex;clangRewrite;clangSerialization;clangToolingCore;LLVM"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/clangTooling.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS clangTooling )
list(APPEND _IMPORT_CHECK_FILES_FOR_clangTooling "${_IMPORT_PREFIX}/lib/libclangTooling.dll.a" "${_IMPORT_PREFIX}/bin/clangTooling.dll" )

# Import target "clangDirectoryWatcher" for configuration "Release"
set_property(TARGET clangDirectoryWatcher APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(clangDirectoryWatcher PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libclangDirectoryWatcher.dll.a"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "LLVM"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/clangDirectoryWatcher.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS clangDirectoryWatcher )
list(APPEND _IMPORT_CHECK_FILES_FOR_clangDirectoryWatcher "${_IMPORT_PREFIX}/lib/libclangDirectoryWatcher.dll.a" "${_IMPORT_PREFIX}/bin/clangDirectoryWatcher.dll" )

# Import target "clangIndex" for configuration "Release"
set_property(TARGET clangIndex APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(clangIndex PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libclangIndex.dll.a"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "clangAST;clangBasic;clangFormat;clangFrontend;clangLex;clangRewrite;clangSerialization;clangToolingCore;LLVM"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/clangIndex.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS clangIndex )
list(APPEND _IMPORT_CHECK_FILES_FOR_clangIndex "${_IMPORT_PREFIX}/lib/libclangIndex.dll.a" "${_IMPORT_PREFIX}/bin/clangIndex.dll" )

# Import target "clangStaticAnalyzerCore" for configuration "Release"
set_property(TARGET clangStaticAnalyzerCore APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(clangStaticAnalyzerCore PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libclangStaticAnalyzerCore.dll.a"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "clangAST;clangASTMatchers;clangAnalysis;clangBasic;clangCrossTU;clangFrontend;clangLex;clangRewrite;LLVM"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/clangStaticAnalyzerCore.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS clangStaticAnalyzerCore )
list(APPEND _IMPORT_CHECK_FILES_FOR_clangStaticAnalyzerCore "${_IMPORT_PREFIX}/lib/libclangStaticAnalyzerCore.dll.a" "${_IMPORT_PREFIX}/bin/clangStaticAnalyzerCore.dll" )

# Import target "clangStaticAnalyzerCheckers" for configuration "Release"
set_property(TARGET clangStaticAnalyzerCheckers APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(clangStaticAnalyzerCheckers PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libclangStaticAnalyzerCheckers.dll.a"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "clangAST;clangASTMatchers;clangAnalysis;clangBasic;clangLex;clangStaticAnalyzerCore;LLVM"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/clangStaticAnalyzerCheckers.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS clangStaticAnalyzerCheckers )
list(APPEND _IMPORT_CHECK_FILES_FOR_clangStaticAnalyzerCheckers "${_IMPORT_PREFIX}/lib/libclangStaticAnalyzerCheckers.dll.a" "${_IMPORT_PREFIX}/bin/clangStaticAnalyzerCheckers.dll" )

# Import target "clangStaticAnalyzerFrontend" for configuration "Release"
set_property(TARGET clangStaticAnalyzerFrontend APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(clangStaticAnalyzerFrontend PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libclangStaticAnalyzerFrontend.dll.a"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "clangAST;clangAnalysis;clangBasic;clangCrossTU;clangFrontend;clangLex;clangStaticAnalyzerCheckers;clangStaticAnalyzerCore;LLVM"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/clangStaticAnalyzerFrontend.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS clangStaticAnalyzerFrontend )
list(APPEND _IMPORT_CHECK_FILES_FOR_clangStaticAnalyzerFrontend "${_IMPORT_PREFIX}/lib/libclangStaticAnalyzerFrontend.dll.a" "${_IMPORT_PREFIX}/bin/clangStaticAnalyzerFrontend.dll" )

# Import target "clangFormat" for configuration "Release"
set_property(TARGET clangFormat APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(clangFormat PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libclangFormat.dll.a"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "clangBasic;clangLex;clangToolingCore;clangToolingInclusions;LLVM"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/clangFormat.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS clangFormat )
list(APPEND _IMPORT_CHECK_FILES_FOR_clangFormat "${_IMPORT_PREFIX}/lib/libclangFormat.dll.a" "${_IMPORT_PREFIX}/bin/clangFormat.dll" )

# Import target "clang" for configuration "Release"
set_property(TARGET clang APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(clang PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/clang.exe"
  )

list(APPEND _IMPORT_CHECK_TARGETS clang )
list(APPEND _IMPORT_CHECK_FILES_FOR_clang "${_IMPORT_PREFIX}/bin/clang.exe" )

# Import target "clang-format" for configuration "Release"
set_property(TARGET clang-format APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(clang-format PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/clang-format.exe"
  )

list(APPEND _IMPORT_CHECK_TARGETS clang-format )
list(APPEND _IMPORT_CHECK_FILES_FOR_clang-format "${_IMPORT_PREFIX}/bin/clang-format.exe" )

# Import target "clangHandleCXX" for configuration "Release"
set_property(TARGET clangHandleCXX APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(clangHandleCXX PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libclangHandleCXX.dll.a"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "clangBasic;clangCodeGen;clangFrontend;clangLex;clangSerialization;clangTooling;LLVM"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/clangHandleCXX.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS clangHandleCXX )
list(APPEND _IMPORT_CHECK_FILES_FOR_clangHandleCXX "${_IMPORT_PREFIX}/lib/libclangHandleCXX.dll.a" "${_IMPORT_PREFIX}/bin/clangHandleCXX.dll" )

# Import target "clangHandleLLVM" for configuration "Release"
set_property(TARGET clangHandleLLVM APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(clangHandleLLVM PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libclangHandleLLVM.dll.a"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "LLVM"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/clangHandleLLVM.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS clangHandleLLVM )
list(APPEND _IMPORT_CHECK_FILES_FOR_clangHandleLLVM "${_IMPORT_PREFIX}/lib/libclangHandleLLVM.dll.a" "${_IMPORT_PREFIX}/bin/clangHandleLLVM.dll" )

# Import target "clang-import-test" for configuration "Release"
set_property(TARGET clang-import-test APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(clang-import-test PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/clang-import-test.exe"
  )

list(APPEND _IMPORT_CHECK_TARGETS clang-import-test )
list(APPEND _IMPORT_CHECK_FILES_FOR_clang-import-test "${_IMPORT_PREFIX}/bin/clang-import-test.exe" )

# Import target "clang-offload-bundler" for configuration "Release"
set_property(TARGET clang-offload-bundler APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(clang-offload-bundler PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/clang-offload-bundler.exe"
  )

list(APPEND _IMPORT_CHECK_TARGETS clang-offload-bundler )
list(APPEND _IMPORT_CHECK_FILES_FOR_clang-offload-bundler "${_IMPORT_PREFIX}/bin/clang-offload-bundler.exe" )

# Import target "clang-offload-wrapper" for configuration "Release"
set_property(TARGET clang-offload-wrapper APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(clang-offload-wrapper PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/clang-offload-wrapper.exe"
  )

list(APPEND _IMPORT_CHECK_TARGETS clang-offload-wrapper )
list(APPEND _IMPORT_CHECK_FILES_FOR_clang-offload-wrapper "${_IMPORT_PREFIX}/bin/clang-offload-wrapper.exe" )

# Import target "clang-scan-deps" for configuration "Release"
set_property(TARGET clang-scan-deps APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(clang-scan-deps PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/clang-scan-deps.exe"
  )

list(APPEND _IMPORT_CHECK_TARGETS clang-scan-deps )
list(APPEND _IMPORT_CHECK_FILES_FOR_clang-scan-deps "${_IMPORT_PREFIX}/bin/clang-scan-deps.exe" )

# Import target "clang-rename" for configuration "Release"
set_property(TARGET clang-rename APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(clang-rename PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/clang-rename.exe"
  )

list(APPEND _IMPORT_CHECK_TARGETS clang-rename )
list(APPEND _IMPORT_CHECK_FILES_FOR_clang-rename "${_IMPORT_PREFIX}/bin/clang-rename.exe" )

# Import target "clang-refactor" for configuration "Release"
set_property(TARGET clang-refactor APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(clang-refactor PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/clang-refactor.exe"
  )

list(APPEND _IMPORT_CHECK_TARGETS clang-refactor )
list(APPEND _IMPORT_CHECK_FILES_FOR_clang-refactor "${_IMPORT_PREFIX}/bin/clang-refactor.exe" )

# Import target "clang-check" for configuration "Release"
set_property(TARGET clang-check APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(clang-check PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/clang-check.exe"
  )

list(APPEND _IMPORT_CHECK_TARGETS clang-check )
list(APPEND _IMPORT_CHECK_FILES_FOR_clang-check "${_IMPORT_PREFIX}/bin/clang-check.exe" )

# Import target "clang-extdef-mapping" for configuration "Release"
set_property(TARGET clang-extdef-mapping APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(clang-extdef-mapping PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/clang-extdef-mapping.exe"
  )

list(APPEND _IMPORT_CHECK_TARGETS clang-extdef-mapping )
list(APPEND _IMPORT_CHECK_FILES_FOR_clang-extdef-mapping "${_IMPORT_PREFIX}/bin/clang-extdef-mapping.exe" )

# Import target "libclang" for configuration "Release"
set_property(TARGET libclang APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(libclang PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libclang.dll.a"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "clangAST;clangBasic;clangDriver;clangFrontend;clangIndex;clangLex;clangSema;clangSerialization;clangTooling;clangARCMigrate;LLVM"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/clang.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS libclang )
list(APPEND _IMPORT_CHECK_FILES_FOR_libclang "${_IMPORT_PREFIX}/lib/libclang.dll.a" "${_IMPORT_PREFIX}/bin/clang.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
