SOURCES := $(shell find . -type d -name leetcode -prune -false -o -name '*.cpp' -print)
EXECUTABLES := $(SOURCES:.cpp=)

CXX := g++
CXXFLAGS := -x c++ -std=gnu++20 -Wall -O2 -static -pipe -DONLINE_JUDGE -DDOMJUDGE

.PHONY: all clean

all: $(EXECUTABLES)

%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	find . -type f ! -path "*/leetcode/*" -name '*.out' -exec rm -f {} +
