CXX = g++
CXXFLAGS = -std=c++11

.PHONY: all clean

all: examheap

examheap: heap.cpp heap.h examheap.cpp
	$(CXX) $(CXXFLAGS) heap.cpp examheap.cpp -o examheap

clean:
	rm -f examheap
