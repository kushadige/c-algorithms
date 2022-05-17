/* Print a pattern of numbers from to as shown below. 
Each of the numbers is separated by a single space.       
   
   Sample Input 1 : 
    5
   Sample Output 1:
    5 5 5 5 5 5 5 5 5 
    5 4 4 4 4 4 4 4 5 
    5 4 3 3 3 3 3 4 5 
    5 4 3 2 2 2 3 4 5 
    5 4 3 2 1 2 3 4 5 
    5 4 3 2 2 2 3 4 5 
    5 4 3 3 3 3 3 4 5 
    5 4 4 4 4 4 4 4 5 
    5 5 5 5 5 5 5 5 5 
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    int n;
    scanf("%d", &n);
  	// Complete the code to print the pattern.
      
    int row = (n*2)-1, column = (n*2)-1;
    for(int i=0;i<row;i++){
        if(i<n-1){
            for(int j=0;j<i;j++){
                printf("%d ", n-j);
            }
            for(int j=0;j<column-(2*i);j++){
                printf("%d ", n-i);
            }
            for(int j=0;j<i;j++){
                printf("%d ", n-i+j+1);
            }
        }
        else {
            for(int j=0;j<column-i-1;j++){
                printf("%d ", n-j);
            }
            for(int j=0;j<(2*(i+1)-column);j++){
                printf("%d ", i-n+2);
            }
            for(int j=0;j<column-i-1;j++){
                printf("%d ", j+i-n+3);
            }
        }
        printf("\n");
    }
    return 0;
}