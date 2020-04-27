CXX=g++
CFLAGS=-c -Wall -std=c++14 -g
LDFLAGS=
SOURCES=main.cpp
LIB=array_rotation/array_rotation.hpp sorted_and_rotated_array_search/search.hpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=array_exec

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(LDFLAGS) $(OBJECTS) $(LIB) -o $@

.cpp.o:
	$(CXX) $(CFLAGS) $< -o $@

run:
	./$(EXECUTABLE)

clean: 
	rm -f $(filter %.o, $(OBJECTS))