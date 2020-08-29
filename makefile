PROGRAM = main

CXX = clang++

MODULES_PATH = .

PRECOMPILE_MODULE_FLAGS = -fmodules-ts --precompile
BUILD_MODULE_FLAGS      = -fmodules-ts -c
BUILD_PROGRAM_FLAGS     = -fmodules-ts -fprebuilt-module-path=$(MODULES_PATH)

precompile:
	$(CXX) $(PRECOMPILE_MODULE_FLAGS) *.cppm

build_modules:
	$(CXX) $(BUILD_MODULE_FLAGS) *.pcm

build_program:
	$(CXX) $(BUILD_PROGRAM_FLAGS) *.o $(PROGRAM).cpp

show:
	@echo "PROGRAM                  : " $(PROGRAM)
	@echo "COMPILER                 : " $(CXX)
	@echo "MODULES_PATH             : " $(MODULES_PATH)

all:
	$(MAKE) precompile
	$(MAKE) build_modules
	$(MAKE) build_program

run:
	./a.out

clean:
	rm *.pcm *.o *.out

help:
	@echo "Software Design: Assignment 1"
	@echo
	@echo 'Usage: make [OPTIONS]'
	@echo 'OPTIONS:'
	@echo '  run            Run the program'
	@echo '  all        Rebuild everything'
	@echo '  precompile     Only compile the modules'
	@echo '  build_modules  Only run preprocess, compile and assemble steps'
	@echo '  build_program  Build the program'
	@echo '  show           Show variables (for debug use only)'
	@echo '  help           print this message.'
