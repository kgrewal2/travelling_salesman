PROGRAM = main

CXX = clang++

MODULES_PATH = .

PRECOMPILE_MODULE_FLAGS = -fmodules-ts --precompile
BUILD_MODULE_FLAGS      = -fmodules-ts -c
BUILD_PROGRAM_FLAGS     = -fmodules-ts -fprebuilt-module-path = $(MODULES_PATH)

precompile:
	$(CXX) $(PRECOMPILE_MODULE_FLAGS) *.cppm
