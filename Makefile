CXX = g++
CFLAGS = -shared --std=c++11 -m64 -fPIC -Wall -Wextra -Werror
PY_INC = /usr/include/python3.8
PYFLAGS = `python3 -m pybind11 --includes` -I $(PY_INC)

SRCDIR = src
OBJDIR = obj
TARGET = _curve
SO_SUFFIX = `python3-config --extension-suffix`
.PHONY: default clean

default: $(OBJDIR) $(TARGET)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/point.o: $(SRCDIR)/point.cpp
	$(CXX) -c $< -o $@ $(CFLAGS)

$(OBJDIR)/curve.o: $(SRCDIR)/curve.cpp
	$(CXX) -c $< -o $@ $(CFLAGS)

$(TARGET): $(SRCDIR)/wrapper.cpp $(OBJDIR)/point.o $(OBJDIR)/curve.o
	$(CXX) $^ -o $@$(SO_SUFFIX) $(CFLAGS) $(PYFLAGS)

clean:
	rm -rf $(TARGET).*.so $(OBJDIR) __pycache__/
