CXX = g++
CXXFLAGS = -Wall -Werror -std=c++11
INCLUDES = -I./include
SRCDIR = src
OBJDIR = obj
LIBDIR = lib
LIBNAME = onoff_controller
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))

# static library target
static: $(LIBDIR)/lib$(LIBNAME).a
	compiledb -n make static

$(LIBDIR)/lib$(LIBNAME).a: $(OBJECTS)
	ar rcs $@ $^

# shared library target
shared: $(LIBDIR)/lib$(LIBNAME).so
	compiledb -n make shared

$(LIBDIR)/lib$(LIBNAME).so: $(OBJECTS)
	$(CXX) -shared -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -fPIC $(INCLUDES) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(OBJECTS) $(LIBDIR)/lib$(LIBNAME).a $(LIBDIR)/lib$(LIBNAME).so compile_commands.json
