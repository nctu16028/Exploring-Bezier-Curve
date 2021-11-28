CXX = g++
CFLAGS = --std=c++11 -Wall -Wextra -Werror
TARGET = test
.PHONY: default run clean

default: $(TARGET)

point.o: point.cpp point.hpp
	$(CXX) -c $< -o $@ $(CFLAGS)

curve.o: curve.cpp curve.hpp
	$(CXX) -c $< -o $@ $(CFLAGS)

main.o: test.cpp curve.hpp
	$(CXX) -c $< -o $@ $(CFLAGS)

$(TARGET): point.o curve.o main.o
	$(CXX) $^ -o $@ $(CFLAGS)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf *.o $(TARGET)
