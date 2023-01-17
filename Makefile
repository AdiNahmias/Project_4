CC = gcc
FLAGS = -Wall -g
AR = ar

all: graph

graph: main.o graphlib.a
	$(CC) $(FLAGS) -o graph main.o graphlib.a

main.o: main.c graph.h 
	$(CC) $(FLAGS) -c main.c 

algo.o: algo.c graph.h
	$(CC) $(FLAGS) -c algo.c

graph.o: graph.c graph.h
	$(CC) $(FLAGS) -c graph.c

graphlib.a: algo.o graph.o
	$(AR) -rcs graphlib.a algo.o graph.o

clean: 
	rm -f *.o *.a graph



