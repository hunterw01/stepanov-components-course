LD_FLAGS := -lstdc++ -lm
CC_FLAGS := -std=c++14 -O3 -Wall

all: collect-data count count-norm

collect-data: sort-ops.o instrumented.o
	clang-3.8 $(LD_FLAGS) -o $@ $^

count: count_operations.o instrumented.o
	clang-3.8 $(LD_FLAGS) -o $@ $^

count-norm: count_operations_normalized.o instrumented.o
	clang-3.8 $(LD_FLAGS) -o $@ $^

%.o: %.cpp
	clang-3.8 $(CC_FLAGS) -c -o $@ $<

sort-ops.cpp: count_operations.h
instrumented.cpp: instrumented.h
count_operations.cpp: count_operations.h

.PHONY: clean
clean:
	rm -rf *.o count count-norm collect-data
