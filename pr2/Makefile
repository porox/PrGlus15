CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=ConsoleApplication2.cpp  material.cpp 
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=pr_3

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
