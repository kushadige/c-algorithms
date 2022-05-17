/*CyclicRotation

Rotate an array to the right by a given number of steps.
 * 
For example, given

    A = [3, 8, 9, 7, 6]
    K = 3
the function should return [9, 7, 6, 3, 8]. Three rotations were made:

    [3, 8, 9, 7, 6] -> [6, 3, 8, 9, 7]
    [6, 3, 8, 9, 7] -> [7, 6, 3, 8, 9]
    [7, 6, 3, 8, 9] -> [9, 7, 6, 3, 8]*/

#include <stdio.h>

struct Results {
    int * A;
    int N; // Length of the array
};

void rotate(int A[], int N, int K){
    if(K > 0){
        int last_element_index = N - 1;

        int temp = A[last_element_index];

        for(int i=0;i<last_element_index;i++)
        A[last_element_index-i] = A[last_element_index-i-1];

        A[0] = temp;

        rotate(A, N, K-1);
    }
}

struct Results solution(int A[], int N, int K){
    
    struct Results result;
    result.A = A;
    result.N = N;
    
    if(K%N == 0)
        return result;
    
    rotate(A, N, K);
    
    return result;
}

int main(){
    int A[0];

    struct Results result = solution(A, 0, 2);

    for(int i=0;i<0;i++){
        printf("%d,", A[i]);
    }
    printf("\n");
}