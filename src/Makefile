CXX = g++
CFLAGS = --std=c++11 -Wall -Wextra -Werror
TARGET = test
.PHONY: default run clean

default: $(TARGET)

curve.o: curve.cpp curve.hpp
	$(CXX) -c $< -o $@ $(CFLAGS)

main.o: test.cpp curve.hpp
	$(CXX) -c $< -o $@ $(CFLAGS)

$(TARGET): curve.o main.o
	$(CXX) $^ -o $@ $(CFLAGS)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf *.o $(TARGET)
