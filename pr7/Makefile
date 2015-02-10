CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=main.cpp 
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=pr_7

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
