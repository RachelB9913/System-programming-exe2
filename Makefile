# OBJECTS_MAT= my_mat.o
# OBJECTS_Knapsack = my_Knapsack.o
# OBJECTS_MAIN= my_graph.o 
# CC = gcc
# AR = ar
# FLAGS = -Wall -g

# all: my_graph my_Knapsack libmy_knapsack.so libmy_mat.so

# my_graph: $(OBJECTS_MAIN) libmy_mat.so 
# 	$(CC) $(FLAGS) -o my_graph $(OBJECTS_MAIN) ./libmy_mat.so 

# my_Knapsack: $(OBJECTS_Knapsack) libmy_knapsack 
# 	$(CC) $(FLAGS) -o my_Knapsack $(OBJECTS_Knapsack) ./libmy_knapsack.so

# libmy_mat.so: $(OBJECTS_MAT)
# 	$(CC) -shared -o libmy_mat.so $(OBJECTS_MAT)

# libmy_knapsack.so: $(OBJECTS_Knapsack)
# 	$(CC) -shared -o libmy_knapsack.so $(OBJECTS_Knapsack)

# my_graph.o: my_graph.c my_mat.h my_mat.c 
# 	$(CC) $(FLAGS) -c -fPIC -o my_graph.o my_graph.c

# my_mat.o: my_mat.c my_mat.h
# 	$(CC) $(FLAGS) -c -fPIC -o my_mat.o my_mat.c

# my_Knapsack.o: my_Knapsack.c my_mat.h
# 	$(CC) $(FLAGS) -c -fPIC -o my_Knapsack.o my_Knapsack.c

# .PHONY: clean all

# clean:
# 	rm -f *.o *.so my_graph my_Knapsack

OBJECTS_MAT = my_mat.o
OBJECTS_Knapsack = my_Knapsack.o
OBJECTS_MAIN = my_graph.o 
CC = gcc
FLAGS = -Wall -g

all: my_graph my_Knapsack libmy_knapsack.so libmy_mat.so

my_graph: $(OBJECTS_MAIN) libmy_mat.so 
	$(CC) $(FLAGS) -o my_graph $(OBJECTS_MAIN) -L. -lmy_mat

my_Knapsack: $(OBJECTS_Knapsack) libmy_knapsack.so 
	$(CC) $(FLAGS) -o my_Knapsack $(OBJECTS_Knapsack) -L. -lmy_knapsack

libmy_mat.so: $(OBJECTS_MAT)
	$(CC) -shared -o libmy_mat.so $(OBJECTS_MAT)

libmy_knapsack.so: $(OBJECTS_Knapsack)
	$(CC) -shared -o libmy_knapsack.so $(OBJECTS_Knapsack)

my_graph.o: my_graph.c my_mat.h 
	$(CC) $(FLAGS) -c -fPIC -o my_graph.o my_graph.c

my_mat.o: my_mat.c my_mat.h
	$(CC) $(FLAGS) -c -fPIC -o my_mat.o my_mat.c

my_Knapsack.o: my_Knapsack.c my_mat.h
	$(CC) $(FLAGS) -c -fPIC -o my_Knapsack.o my_Knapsack.c

.PHONY: clean all

clean:
	rm -f *.o *.so my_graph my_Knapsack
