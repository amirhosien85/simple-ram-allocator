
CC = gcc
CFLAGS = -Wall -g

all: simulation


simulation: main.o memory.o
	$(CC) $(CFLAGS) -o simulation main.o memory.o

main.o: main.c memory.h
	$(CC) $(CFLAGS) -c main.c

memory.o: memory.c memory.h
	$(CC) $(CFLAGS) -c memory.c

clean:
	del *.o simulation.exe