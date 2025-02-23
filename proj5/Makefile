CC = gcc
CFLAGS = -std=c99 -Wall -Werror -g

SOURCES = Boolean.c main.c Circuit.c strdup.c Gates.c BoolCircuits.c
OBJECTS = $(SOURCES:.c=.o)
EXECUTABLE = proj5

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXECUTABLE)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -f $(OBJECTS) $(EXECUTABLE)

.PHONY: all clean