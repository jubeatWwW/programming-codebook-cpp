CXX=g++
CFLAGS=-c -Wall -std=c++14 -g
LDFLAGS=
SOURCES=main.cpp array_rotation.hpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=array_rotation

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CXX) $(CFLAGS) $< -o $@

run:
	./$(EXECUTABLE)

clean: 
	rm -f $(filter %.o, $(OBJECTS))