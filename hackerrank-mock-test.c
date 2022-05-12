/* HackerRank Mock Test - Flipping the Matrix
 QUESTION DESCRIPTION
- Sean invented a game involving a 2n x 2n matrix where each cell  of the matrix 
- contains an integer. He can reverse any of its rows or columns any number of times. 
- The goal of the game is to maximize the sum of the elements in the n x n submatrix 
- located in the upper-left quadrant of the matrix.
 
 Example
matrix = [[1,2][2,3]]
    1 2
    3 4
     
- It is 2 x 2 and we want to maximize the top left quadrant, a 1 x 1 matrix. Reverse row 1:
    1 2 
    4 3  <-- reversed
     
- And now reverse column 0:
    4 2
    1 3
     
- The maximal sum is 4.
 */
#include <stdio.h>
#include <stdlib.h>

void reverse_row(int matrix_rows, int matrix_columns, int **matrix, int num){
    for(int i=0;i<matrix_rows;i++){
        for(int j=0;j<matrix_columns;j++){
            if(i == num && j<matrix_columns/2){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][matrix_columns-1-j];
                matrix[i][matrix_columns-1-j] = temp;
            }
        }
    }
}
void reverse_column(int matrix_rows, int matrix_columns, int **matrix, int num){
    for(int i=0;i<matrix_rows;i++){
        for(int j=0;j<matrix_columns;j++){
            if(j == num && i<matrix_rows/2){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[matrix_rows-1-i][j];
                matrix[matrix_rows-1-i][j] = temp;
            }
        }
    }
}

int flippingMatrix(int matrix_rows, int matrix_columns, int** matrix) {
    
/*  -- must return -> 488
    107 54 128 15
    12 75 110 138
    100 96 34 85
    75 15 28 112 

    -- must return -> 414
    112 42 83 119
    56 125 56 49
    15 78 101 43
    62 98 114 108     */
    
    int sum=0;
    for(int i=0;i<matrix_rows/2;i++)
        for(int j=0;j<matrix_columns/2;j++){
            
            if(matrix[i][matrix_columns-1-j] > matrix[i][j])
                reverse_row(matrix_rows,matrix_columns,matrix,i);
                
            if(matrix[matrix_rows-1-i][j] > matrix[i][j])
                reverse_column(matrix_rows,matrix_columns,matrix,j);
                
            if(matrix[matrix_rows-1-i][matrix_columns-1-j] > matrix[i][j]){
                reverse_row(matrix_rows,matrix_columns,matrix,matrix_rows-1-i); 
                reverse_column(matrix_rows,matrix_columns,matrix,j);
            }
                                                                    
            sum += matrix[i][j];
        }
    
    return sum;
}

int main(){
    
    // create matrix
    int **matrix = malloc(sizeof(int*) * 4);
    for(int i=0;i<4;i++)
        matrix[i] = malloc(sizeof(int) * 4);
            
    // initialize matrix
    int temp[16] = {
        107,54,128,15,
        12,75,110,138,
        100,96,34,85,
        75,15,28,112
        };
        
    int a=0;
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            matrix[i][j] = temp[a++];
    
    
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
    
    int maxsum = flippingMatrix(4,4,matrix);
    
    printf("\nmaxsum: %d", maxsum);
}


/*  FOR OPTIMIZE (!you should optimize in order to pass the test)
 *  1- delete reverse_row(), reverse_column() 
 *  2- change flippingMatrix() function like below

 
int flippingMatrix(int matrix_rows, int matrix_columns, int** matrix) {
    int sum=0;
    for(int i=0;i<matrix_rows/2;i++)
        for(int j=0;j<matrix_columns/2;j++){
            
            if(matrix[i][matrix_columns-1-j] > matrix[i][j]){
                matrix[i][j] = matrix[i][matrix_columns-1-j];
            }
                
            if(matrix[matrix_rows-1-i][j] > matrix[i][j])
                matrix[i][j] = matrix[matrix_rows-1-i][j];
                
            if(matrix[matrix_rows-1-i][matrix_columns-1-j] > matrix[i][j]){
                matrix[i][j] = matrix[matrix_rows-1-i][matrix_columns-1-j];
            }
                                                                    
            sum += matrix[i][j];
        }
    
    return sum;
}



*/