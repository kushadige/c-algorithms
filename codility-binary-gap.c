/* A binary gap within a positive integer N is any maximal sequence of 
consecutive zeros that is surrounded by ones at both ends in the binary 
representation of N.

For example, number 9 has binary representation 1001 and contains a binary 
gap of length 2. The number 529 has binary representation 1000010001 
and contains two binary gaps: one of length 4 and one of length 3. The number 
20 has binary representation 10100 and contains one binary gap of length 1. 
The number 15 has binary representation 1111 and has no binary gaps. The 
number 32 has binary representation 100000 and has no binary gaps.

Write a function:

    int solution(int N);

that, given a positive integer N, returns the length of its longest binary gap. 
The function should return 0 if N doesn't contain a binary gap.

For example, given N = 1041 the function should return 5, because N has 
binary representation 10000010001 and so its longest binary gap is of length 
5. Given N = 32 the function should return 0, because N has binary 
representation '100000' and thus no binary gaps.

Write an efficient algorithm for the following assumptions:

    * N is an integer within the range [1..2,147,483,647]. */

#include <stdio.h>
#include <stdlib.h>

void reverse(char *s, int size){
    int i = 0;
    while(i != size/2){
        char temp = s[i];
        s[i] = s[size-i-1];
        s[size-i-1] = temp;
        i++;
    }
}

char* binary(int num){
    //num = 15 -> 7 3 1 0 -> 1 1 1 1 ✔
    //num = 19 -> 9 4 2 1 0 -> 1 1 0 0 1 ✘ reverse -> 1 0 0 1 1 ✔
    
    // find binary length
    int temp = num;
    int i = 0;
    while(temp != 0){
        i++;
        temp /= 2;
    }
    
    // create array, assign binary values
    char* bin = malloc(sizeof(char) * i-1);
    i = 0;
    while(num != 0){
        bin[i] = (num%2 + 48);
        i++;
        num /= 2;
    }
    bin[i] = '\0';
    
    // reverse array
    reverse(bin, i);

    return bin;
}

int solution(int N) {
    // write your code in C99 (gcc 6.2.0)
    
    // convert decimal number to binary first
    char * num = binary(N);
    
    // find gaps and assign them all to 
    // an array which called 'sizes' like below
    int i = 0, j = 0;  
    int count0 = 0;
    int sizes[1024];
    while(num[i] != '\0'){
        if(num[i] == 49){
            i++;
            while(num[i] != 49){
                count0++;
                i++;
                if(num[i] == '\0'){
                    count0 = 0;
                    break;
                }
            }
        } 
        sizes[j] = count0;
        j++;
        count0 = 0;
        i++;
        if(num[i-1] == 49)
            i = i-1;
    }
    
    // finally find the largest value in the sizes array
    i = 1;
    int max = sizes[0];
    while(sizes[i] != '\0'){
        if(sizes[i] > max)
            max = sizes[i];
        i++;
    }
    
    // return largest value
    return max;
}

int main(){
    
    int N = 6291457;
    printf("%d\n", solution(N));
    
        // Passed all tests except this one.
    // for n=74901729=100011101101110100011100001 ✘WRONG ANSWER got 3 expected 4
}