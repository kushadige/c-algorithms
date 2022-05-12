/*
You will have an orthogonal triangle input from a file and you need to find the maximum sum of the numbers according to given rules below;

1. You will start from the top and move downwards to an adjacent number as in below.
2. You are only allowed to walk downwards and diagonally.
3. You can only walk over NON PRIME NUMBERS.
4. You have to reach at the end of the pyramid as much as possible.
5. You have to treat your input as pyramid.

According to above rules the maximum sum of the numbers from top to bottom in below example is 24.

      *1
     *8 4
    2 *6 9
   8 5 *9 3

As you can see this has several paths that fits the rule of NOT PRIME NUMBERS; 1>8>6>9, 1>4>6>9, 1>4>9>9
1 + 8 + 6 + 9 = 24.  As you see 1, 8, 6, 9 are all NOT PRIME NUMBERS and walking over these yields the maximum sum.

You can implement by using any programming language except Mathlab. Please paste the link to your code.
*/
#include <stdio.h>
#include <math.h>

// Prime control function
int is_prime(int x){
    if(x == 1 || x == 0 || x < 0)
        return 0;
        
    int prime = 1;
    for(int i=1;i<x/2;i++){
        if(x%(i+1) == 0)
            prime = 0;
    }
    
    return prime;
}
int main(){
	// Opening file in order to read given numbers
    FILE* fp;
    fp = fopen("input.txt", "r");
    if(fp == NULL){
        printf("failed to open file\n");
        exit(1);
    }
    
    // Calculate row count
    char buffer;
    int row_count = 0;
    while((buffer = fgetc(fp)) != EOF)
        if(buffer == 10){
            row_count++;
        }
    row_count++;
    fclose(fp);


    // Create an array and assign given numbers to it
    fp = fopen("input.txt", "r");

	// If row_count 4 -> total element will be 20. (1+2+3+4 -> 4*5/2)
    int total_elements = (row_count*(row_count+1)/2);
    int elements[total_elements]; 
    
	// The number can be 2 digits or 3 digits or something else. Calculate and assign it to a integer value
    int counter=0,element=0,digit=0;
    int temp[8];
    char last_element;
    while((buffer = fgetc(fp)) != EOF){
        if(buffer != 32 && buffer != 10){ // if buffer not equal ' ' space char and '\n'
            last_element = buffer;
            temp[digit] = buffer;
            digit++;
        } else {
            for(int i=0;i<digit;i++){   // turn given number to integer
                element += (temp[i]-48) * pow(10,(digit-i-1));
            }
        }
        if(element > 0){  // append element to array 
            elements[counter] = element;
            counter++;
            digit = 0;
            element = 0;
        }
    }
    // Assign last element
    for(int i=0;i<digit;i++)  
        element += (last_element-48) * pow(10,(digit-i-1));
    elements[total_elements-1] = element;
    
    
    // Indexlere göre karşılaştırma yaparak maksimum toplamı bulan algoritma
    int selected_num;
    int selected_index = 0;
    int max_sum = elements[0];
    for(int i=0;i<row_count-1;i++){
        if(elements[selected_index+i+1] > elements[selected_index+i+2]){
            // Check prime
            if(is_prime(elements[selected_index+i+1]))
                selected_index = selected_index+i+2;
            else {
                selected_index = selected_index+i+1;
            }
        } else if(elements[selected_index+i+1] == elements[selected_index+i+2]) {
            selected_index = selected_index+i+1;
        } else {
            // Check prime
            if(is_prime(elements[selected_index+i+2]))
                selected_index = selected_index+i+1;
            else {
                selected_index = selected_index+i+2;
            }
        }
        selected_num = elements[selected_index];
        max_sum += selected_num; 
    }
    
    fclose(fp);
    
    printf("max sum: %d", max_sum);
}