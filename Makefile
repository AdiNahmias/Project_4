CC = gcc
CFLAGS = -Wall -g -fPIC

all: graph

graph:  graph.o main.o algo.o
	$(CC) $(CFLAGS) $^ -o $@


%.o:%.c
	$(CC) $(CFLAGS) -c $^ -o $@

.PHONY: clean all

clean:
	rm  *.o graph



