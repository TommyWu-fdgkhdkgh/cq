CPLUSFLAGS = 
CFLAGS = 
CPLUSLINKFLAGS = -lgmock -lgtest -lpthread
COVERAGE = 

ifeq ($(COVERAGE),TRUE)
    COVERAGE_FLAGS = -fprofile-instr-generate -fcoverage-mapping 
    CPLUSFLAGS += $(COVERAGE_FLAGS)
    CPLUSLINKFLAGS += $(COVERAGE_FLAGS)
endif

all: test1

test1: test1.o 
	clang++ ./test1.o -o test1 $(CPLUSLINKFLAGS)

test1.o: test1.cpp
	clang++ -c test1.cpp -I../ $(CPLUSFLAGS)
	
clean:
	rm -f test1.o test1 default.profraw default.profdata


