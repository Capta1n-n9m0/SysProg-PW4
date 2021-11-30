ARGS			=1 2 3 4
EXECUTABLE		=main
CC				=gcc
CFLAGS			=-Wall -Werror --pedantic -std=c11
LDFLAGS			=
SOURCES			=$(wildcard *.c)
HEADERS			=$(wildcard *.h)
OBJECTS			=$(SOURCES:.c=.o)

all: $(EXECUTABLE)
	./$(EXECUTABLE) $(ARGS)

valgrind: $(EXECUTABLE)
	valgrind --leak-check=full -v ./$(EXECUTABLE) $(ARGS)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $(EXECUTABLE)

main.o: main.c
	$(CC) $(CFLAGS) 	-c -o main.o main.c

.PHONY: clean
clean:
	-rm $(OBJECTS)

# prepare: $(SOURCES) $(HEADERS)
# 	python3 prepare_file.py $(SOURCES) $(HEADERS) makefile test.txt ex3test.txt
