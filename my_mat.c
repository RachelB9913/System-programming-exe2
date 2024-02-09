#include <stdio.h>
#include "my_mat.h"
#define INF 999999 // a very big number so no matter what number will be in the matrix it will be considered as the new minimum


void getMatrix(int mat[][SIZE]){
    int i , j , value;
    //scans 100 int values and put each of them in place
    for(i=0;i<SIZE;i++){
        for(j=0;j<SIZE;j++){
            scanf("%d" , &value); 
            mat[i][j] = value;
        }
    }
}

//finds the vertex with minimum weight value, from the set of vertices not yet visited in in shortest path.
int minDistance(int dist[], int beenThere[], int n) {
    int min = INF, min_index, v;
    for (v = 0; v < n; v++) {
        if (beenThere[v]==0 && dist[v]<=min) {
            min= dist[v];
            min_index= v;
        }
    }
    return min_index;
}

int shortestPath(int i, int j, int mat[][SIZE], int beenThere[SIZE]){
    int dist[SIZE];
    int v,k, count;
    //initiates 2 arrays to use in the function
    for (v = 0; v < SIZE; v++) {
        dist[v] = INF;
        beenThere[v] = 0; //all the vertices haven't been visited yet
    }
    dist[i] = 0; //from the vertex to itself - the distance is 0

    for (count = 0; count < SIZE - 1; count++) {
        int u = minDistance(dist, beenThere, SIZE);
        beenThere[u] = 1;
        for (v = 0; v < SIZE; v++) {
            if (beenThere[v]==FALSE && mat[u][v]!=0 && dist[u]!=INF && dist[u]+mat[u][v]<dist[v]) {
                dist[v] = dist[u] + mat[u][v];
            }
        }
    }
    //if the max number didnt change - there is no way between the 2 vertices - chang the distance to -1
    for(k=0;k<SIZE;k++){ 
        if(dist[k]==INF){
            dist[k]=-1;
        }
    }
    return dist[j];
}

int isTherePath(int i, int j, int mat[][SIZE], int beenThere[SIZE]){
    int dist = shortestPath(i,j,mat, beenThere);
    if(dist>0){
        return TRUE;
    }
    else{
        return FALSE;
    }
}


    