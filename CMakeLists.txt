# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("HaxorCompiler")

set(CMAKE_CXX_STANDARD 20)
set(BUILD_ARCH "-m64")
set(TARGET_64 ON)
set (C_COMPILER clang++)
set (C_FLAGS -g -O3)
#Packages
find_package(LLVM REQUIRED CONFIG)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")


add_executable(${PROJECT_NAME} main.cpp )

# Set your project compile flags.
# E.g. if using the C++ header files
# you will need to enable C++11 support
# for your compiler.
include_directories(${LLVM_INCLUDE_DIRS})
separate_arguments(LLVM_DEFINITIONS_LIST NATIVE_COMMAND ${LLVM_DEFINITIONS})
add_definitions(${LLVM_DEFINITIONS_LIST})

# Include sub-projects.
#add_subdirectory (Ast)
#add_subdirectory (CodeGen)
#add_subdirectory (Compiler)
add_subdirectory (Lexer)
#add_subdirectory (Parser)
#add_subdirectory (TypeChecker)


#add_subdirectory (external/llvm-project/llvm)

# Find the libraries that correspond to the LLVM components
# that we wish to use
llvm_map_components_to_libnames(llvm_libs
	aarch64asmparser 
	aarch64codegen 
	aarch64desc 
	aarch64disassembler 
	aarch64info 
	aarch64utils 
	aggressiveinstcombine all
	amdgpuasmparser 
	amdgpucodegen 
	amdgpudesc 
	amdgpudisassembler 
	amdgpuinfo
	amdgputargetmca 
	amdgpuutils 
	analysis
	armasmparser 
	armcodegen 
	armdesc
	armdisassembler 
	arminfo 
	armutils 
	asmparser
	asmprinter 
	avrasmparser 
	avrcodegen
	avrdesc 
	avrdisassembler 
	avrinfo
	binaryformat
	bitreader 
	bitstreamreader 
	bitwriter
	bpfasmparser 
	bpfcodegen 
	bpfdesc
	bpfdisassembler 
	bpfinfo 
	cfguard 
	codegen
	core
	coroutines 
	coverage 
	debuginfocodeview 
	debuginfodwarf 
	debuginfogsym 
	debuginfomsf
	debuginfopdb 
	demangle
	dlltooldriver
	dwarflinker
	dwp
	executionengine 
	extensions
	filecheck 
	frontendopenacc 
	frontendopenmp 
	fuzzmutate 
	globalisel
	hexagonasmparser 
	hexagoncodegen 
	hexagondesc 
	hexagondisassembler 
	hexagoninfo 
	instcombine 
	instrumentation 
	interfacestub 
	interpreter 
	ipo 
	irreader 
	jitlink
	lanaiasmparser 
	lanaicodegen 
	lanaidesc 
	lanaidisassembler 
	lanaiinfo 
	libdriver 
	lineeditor 
	linker 
	lto 
	mc 
	mca 
	mcdisassembler 
	mcparser 
	mipsasmparser 
	mipscodegen 
	mipsdesc 
	mipsdisassembler 
	mipsinfo 
	mirparser
	msp430asmparser 
	msp430codegen 
	msp430desc 
	msp430disassembler 
	msp430info 
	native 
	nativecodegen 
	nvptxcodegen 
	nvptxdesc 
	nvptxinfo 
	objcarcopts 
	object 
	objectyaml option 
	orcshared 
	orctargetprocess 
	passes 
	powerpcasmparser 
	powerpccodegen 
	powerpcdesc 
	powerpcdisassembler 
	powerpcinfo 
	profiledata 
	remarks 
	riscvasmparser 
	riscvcodegen 
	riscvdesc 
	riscvdisassembler 
	riscvinfo 
	runtimedyld 
	scalaropts 
	selectiondag 
	sparcasmparser 
	sparccodegen 
	sparcdesc 
	sparcdisassembler 
	sparcinfo 
	support 
	symbolize 
	systemzasmparser 
	systemzcodegen 
	systemzdesc 
	systemzdisassembler 
	systemzinfo 
	tablegen target 
	textapi 
	transformutils 
	veasmparser 
	vecodegen 
	vectorize 
	vedesc 
	vedisassembler 
	veinfo 
	webassemblyasmparser 
	webassemblycodegen 
	webassemblydesc 
	webassemblydisassembler 
	webassemblyinfo 
	webassemblyutils 
	windowsmanifest 
	x86asmparser 
	x86codegen 
	x86desc 
	x86disassembler 
	x86info 
	x86targetmca 
	xcorecodegen 
	xcoredesc 
	xcoredisassembler 
	xcoreinfo 
	xray
)


target_link_libraries(${PROJECT_NAME} Lexer ${llvm_libs})