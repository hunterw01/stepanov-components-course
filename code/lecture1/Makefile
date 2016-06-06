LD_FLAGS := -lstdc++
CC_FLAGS := -std=c++14 -O3 -Wall

all: count count-norm

count: count_operations.o instrumented.o
	clang $(LD_FLAGS) -o $@ $^

count-norm: count_operations_normalized.o instrumented.o
	clang $(LD_FLAGS) -o $@ $^

%.o: %.cpp
	clang $(CC_FLAGS) -c -o $@ $<

instrumented.cpp: instrumented.h
count_operations.cpp: count_operations.h

.PHONY: clean
clean:
	rm -rf *.o count count-norm
