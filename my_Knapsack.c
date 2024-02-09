#include <stdio.h>
#define BAG_SIZE 5
#define MAX_WEIGHT 20
#define TRUE 1
#define FALSE 0

typedef struct { //creates a struct that represents an item.
    char name; //a,b,c,d,e
    int value;
    int weight;
} Item;

//gets 2 int numbers and returns the bigger one
int max(int x, int y){
    if(x>y){
        return x;
    }
    return y;
}

int knapSack(int weights[], int values[], int selected_bool[]) {
    int i,j,w;
    int result[BAG_SIZE]={0}; //stores selected items
    int table[BAG_SIZE + 1][MAX_WEIGHT + 1]; //reference table - stores the weights in each step with/witout the items according to the weight and the value of the item.

    for (i = 0; i<BAG_SIZE+1; i++) {
        for (j = 0; j<MAX_WEIGHT+1; j++) {
            if (i == 0 || j==0)
                table[i][j] = 0;
            else if (weights[i-1] <= j)
                table[i][j] = max(table[i-1][j-weights[i-1]]+values[i-1], table[i-1][j]);
            else
                table[i][j] = table[i-1][j]; 
        }
    }

    w = MAX_WEIGHT;
    for (i=BAG_SIZE; i>0 && w>0; i--) {
        if (table[i][w] != table[i-1][w]) {
            result[i-1] = TRUE; //mark as selected
            w = w-weights[i-1];
        } else {
            result[i-1] = FALSE; //not selected
        }
    }

    //copy the selected items into selected_bool
    for (i=0; i<BAG_SIZE; i++) {
        selected_bool[i] = result[i];
    }

    return table[BAG_SIZE][MAX_WEIGHT];
}

int main(){
    Item item[BAG_SIZE]; //creates an array of items
    int i, bag;
    int weights[BAG_SIZE]={0};
    int values[BAG_SIZE]={0};
    int selected_bool[BAG_SIZE]={0}; //array that shows - if we inserted the item to the bag or not
    for(i=0;i<BAG_SIZE;i++){
        scanf(" %c %d %d" , &item[i].name, &item[i].value, &item[i].weight);
        weights[i] = item[i].weight; //insert to the array that will send to the function the relevant weight
        values[i] = item[i].value;   //insert to the array that will send to the function the relevant value
    }
    
    bag = knapSack(weights, values , selected_bool);
    printf("Maximum profit: %d",bag);
    printf("\nSelected items:");
    for(i=0;i<BAG_SIZE;i++){
        if(selected_bool[i]!=0){
            printf(" %c",item[i].name);
        }
    }
}

