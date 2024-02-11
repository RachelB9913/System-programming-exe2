#include "my_mat.h"
#include <stdio.h>
//if doesn't compile - export LD_LIBRARY_PATH=/path/to/directory:$LD_LIBRARY_PATH in the cmd

int main() {
    char func='A'; //just in order to get inside of the loop for the first time
    int mat[SIZE][SIZE];
    int source, dest, isPath, distPath;
    
    while(func!='D' || EOF){
        scanf(" %c" , &func);
        if(func=='A'){
            getMatrix(mat);
        }
        if(func=='B'){
            scanf(" %d" , &source);
            scanf(" %d" , &dest);
            int beenThere[SIZE]={0};
            isPath= isTherePath(source, dest, mat, beenThere);
            if(isPath==FALSE){
                printf("False\n");
            }
            else{
                printf("True\n");
            }
        }
        if(func=='C'){
            scanf(" %d" , &source);
            scanf(" %d" , &dest);
            int beenThere[SIZE]={0};
            distPath = shortestPath(source, dest, mat, beenThere);
            if(distPath>0){
                printf("%d\n", distPath);
            }
            else{
                printf("-1\n");
            }
        }
        if(func=='D'){
            return 0;
        }
    }
    return 0;
}

