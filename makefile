PROGRAM = main
PROGRAM_MODULES = data_extractor

CXX = clang++

MODULES_PATH        = .
PREBUILD_MODULES_PATH        = -fprebuilt-module-path=$(MODULES_PATH)
ENABLE_MODULES_FLAG = -fmodules-ts $(PREBUILD_MODULES_PATH)

PRECOMPILE_MODULE =  $(ENABLE_MODULES_FLAG) --precompile
BUILD_MODULE      =  $(ENABLE_MODULES_FLAG) -c

build_all_module:
	@read -p "Enter Module Name:" module; \
	$(CXX) $(PRECOMPILE_MODULE) $$module.cppm;\
	$(CXX) $(BUILD_MODULE) $(MODULES_PATH)/*.o $$module.pcm;\

build_module:
	@read -p "Enter Module Name:" module; \
	$(CXX) $(PRECOMPILE_MODULE) $$module.cppm;\
	$(CXX) $(BUILD_MODULE) $(MODULES_PATH)/*.o $$module.pcm;\

build_program:
	$(CXX) $(ENABLE_MODULES_FLAG) *.o $(PROGRAM).cpp

show:
	@echo "PROGRAM                  : " $(PROGRAM)
	@echo "COMPILER                 : " $(CXX)
	@echo "MODULES_PATH             : " $(MODULES_PATH)

run:
	./a.out

clean:
	rm *.pcm *.o

help:
	@echo "Software Design: Assignment 1"
	@echo
	@echo 'Usage: make [OPTIONS]'
	@echo 'OPTIONS:'
	@echo '  run            Run the program'
	@echo '  all            Compile and Clean'
	@echo '  precompile     Only compile the modules'
	@echo '  build_modules  Only run preprocess, compile and assemble steps'
	@echo '  build_program  Build the program'
	@echo '  show           Show variables (for debug use only)'
	@echo '  help           print this message.'
