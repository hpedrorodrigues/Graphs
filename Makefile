CC=g++
CFLAGS=-c -Wall
SOURCES=src/main.cpp src/model/Edge.cpp src/model/Vertex.cpp src/model/Graph.cpp src/run/Runner.cpp src/constants/Constants.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=graphs

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) ; $(CC) $(OBJECTS) -o $@

.cpp.o: ; $(CC) $(CFLAGS) $< -o $@

clean: ; rm $(OBJECTS) ; rm graphs