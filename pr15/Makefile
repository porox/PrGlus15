CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=    main.cpp avtomat.cpp student.cpp kr.cpp exam.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=pr_14

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
