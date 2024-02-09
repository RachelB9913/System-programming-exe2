#define TRUE 1
#define FALSE 0
#define SIZE 10

//receives a matrix and fills it with values that represent the weight of the side between 2 vertices.
void getMatrix(int [][SIZE]);

//returns if there is a path between 2 given vertices or not
int isTherePath(int i, int j, int mat[][SIZE], int beenThere[SIZE]);

//returns the length of the shortest path between 2 given vertices
int shortestPath(int i, int j, int mat[][SIZE], int beenThere[SIZE]);