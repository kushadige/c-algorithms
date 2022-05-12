#include <stdio.h>
#include <stdlib.h>

void flippingMatrix(int row_count, int column_count, int** matrix){
    
    // replacing 1 with 0 && 0 with 1
    for(int i=0;i<row_count;i++)
        for(int j=0;j<column_count;j++){
            if(matrix[i][j]==0)
                matrix[i][j] = 1;
            else
                matrix[i][j] = 0;
        }
        
    // fliping horizontally
    for(int i=0;i<row_count;i++)
        for(int j=0;j<column_count;j++){
            if(i<row_count/2){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[row_count-1-i][j];
                matrix[row_count-1-i][j] = temp;
            }
        }
}

int main(){

    //  1 1 0 0
    //  0 1 0 0   ->  flip the matrix horizontally, replace 1 with 0 and replace 0 with 1
    //  0 0 1 1

    // create a matrix
    int row_count=3,column_count=4;
    int** matrix = malloc(sizeof(int*) * row_count);
    
    for(int i=0;i<column_count;i++)
        matrix[i] = malloc(sizeof(int) * column_count);
    
    // initialize matrix
    int temp[12] = {1,1,0,0,0,1,0,0,0,0,1,1};
    int a = 0;
    for(int i=0;i<row_count;i++)
        for(int j=0;j<column_count;j++)
            matrix[i][j] = temp[a++];
    
    // first view of the matrix
    printf("--raw matrix--\n");
    for(int i=0;i<row_count;i++){
        for(int j=0;j<column_count;j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
    printf("\n");
    
    flippingMatrix(row_count,column_count,matrix);
    
    // view after flipping
    printf("--after flip and replace--\n");
    for(int i=0;i<row_count;i++){
        for(int j=0;j<column_count;j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}