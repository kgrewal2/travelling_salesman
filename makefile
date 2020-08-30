PROGRAM = main
PROGRAM_MODULES =vector_ops str_ops scraper geometry tsp_algo

CXX = clang++

PREBUILD_MODULES_PATH        = -fprebuilt-module-path=.
ENABLE_MODULES_FLAG = -fmodules-ts $(PREBUILD_MODULES_PATH)

PRECOMPILE_MODULE =  $(CXX) $(ENABLE_MODULES_FLAG) --precompile
BUILD_MODULE      =  $(CXX) $(ENABLE_MODULES_FLAG) -c
BUILD_PROGRAM     =  $(CXX) $(ENABLE_MODULES_FLAG) *.o

# DO NOT CHANGE THE ORDER OF THESE ITEMS
MODULES = vector_ops str_ops scraper geometry tsp_algo

build_module:
	@read -p "Enter Module Name: " module; \
		$(PRECOMPILE_MODULE) $$module.cppm;\
		$(BUILD_MODULE) $$module.pcm;\

build_program:
	@$(BUILD_PROGRAM) $(PROGRAM).cpp -o main.out

all:
	@$(foreach dir,$(MODULES), $(PRECOMPILE_MODULE) $(dir).cppm; $(BUILD_MODULE) $(dir).pcm;)
	@$(MAKE) build_program
	@echo "Done"

show:
	@echo "PROGRAM                  : " $(PROGRAM)
	@echo "COMPILER                 : " $(CXX)
	@echo "MODULES                  : " $(MODULES)

clean:
	@rm -f *.pcm *.o
	@echo "Cleaned Successfully!"

help:
	@echo "Software Design: Assignment 1"
	@echo "Run the program with './main.out path_to_data_file'"
	@echo
	@echo 'Usage: make [OPTIONS]'
	@echo 'OPTIONS:'
	@echo '  all            Build default modules and program'
	@echo '  build_module   Build module'
	@echo '  build_program  Build the program with prebuild modules'
	@echo '  show           Show variables (for debug use only)'
	@echo '  help           print this message.'
