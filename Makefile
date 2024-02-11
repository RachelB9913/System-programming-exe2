OBJECTS_MAT = my_mat.o
OBJECTS_Knapsack = my_Knapsack.o
OBJECTS_MAIN = my_graph.o 
CC = gcc
AR = ar
FLAGS = -Wall -g

all: my_graph my_Knapsack libmy_knapsack.a libmy_mat.a

my_graph: $(OBJECTS_MAIN) libmy_mat.a						#static
	$(CC) $(FLAGS) -o my_graph $(OBJECTS_MAIN) libmy_mat.a

my_Knapsack: $(OBJECTS_Knapsack) libmy_knapsack.a						#static
	$(CC) $(FLAGS) -o my_Knapsack $(OBJECTS_Knapsack) libmy_knapsack.a

libmy_mat.a: $(OBJECTS_MAT)
	$(AR) -rcs libmy_mat.a $(OBJECTS_MAT)

libmy_knapsack.a: $(OBJECTS_Knapsack)
	$(AR) -rcs libmy_knapsack.a $(OBJECTS_Knapsack)

my_graph.o: my_graph.c my_mat.h 
	$(CC) $(FLAGS) -c -fPIC -o my_graph.o my_graph.c

my_mat.o: my_mat.c my_mat.h
	$(CC) $(FLAGS) -c -fPIC -o my_mat.o my_mat.c

my_Knapsack.o: my_Knapsack.c 
	$(CC) $(FLAGS) -c -fPIC -o my_Knapsack.o my_Knapsack.c

.PHONY: clean all

clean:
	rm -f *.o *.a my_graph my_Knapsack
