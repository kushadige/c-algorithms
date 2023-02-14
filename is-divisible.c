#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdarg.h>

int get_length(int num) {
    int length = 0;
    do {
        length++;
        num /= 10;
    } while(num != 0);
    return length;
}
int str_length(char *s) {
    int length = 0;
    for(int i = 0; *(s+i) != '\0'; i++) {
        length++;
    }
    return length;
}
char* concat_str(int strc,...) {
    va_list valist;
    
    va_start(valist, strc);
    int concat_str_length = 0;
    for (int i = 0; i < strc; i++) {
        char *current_str = va_arg(valist, char*);
        concat_str_length += str_length(current_str);
    }
    
    va_start(valist, strc);
    char *s = malloc(concat_str_length);
    int s_iterator = 0;
    for (int i = 0; i < strc; i++) {
        char *current_str = va_arg(valist, char*);
        int current_str_length = str_length(current_str);
        for(int j = 0; j < current_str_length; j++) {
            *(s + s_iterator) = *(current_str + j);
            s_iterator++;
        }
    }
    *(s + concat_str_length) = '\0';
    va_end(valist);
    
    return s;
}
char* to_str(int num) {
    int length = get_length(num);
    
    char *s = malloc(length);
    int temp;
    for(int i = 0; i < length; i++) {
        temp = num / pow(10, length-i-1);
        *(s + i) = (char)temp+48;
        if(num != 0) {
            num %= (int)pow(10, length-i-1);
        }
    }
    *(s + length) = '\0';
    return s;
}
char* float_to_str(float f) {
    int ipart = (int)f;
    float fpart = f - ipart;
    
    for(;;) {
        int fipart = (int)fpart;
        float ffpart = fpart - fipart;
        if(ffpart == 0) {
            break;
        }
        fpart *= 10;
    }
    char *s = concat_str(3, to_str(ipart), ".", to_str((int)fpart));
    
    return s;
}
char* is_divisible(int num) {
    if(num <= 0) {
        return "enter positive number";
    }
    
    int sum_of_digits = 0;
    
    int control = num;
    while(control != 0) {
        sum_of_digits += control%10;
        control /= 10;
    }
    
    char *output;
    if(num % sum_of_digits == 0) {
        output = concat_str(6, to_str(num), " is divisible by ", to_str(sum_of_digits), " (result: ", to_str(num/sum_of_digits), ")");
    } else {
        float remainder = (float)num/sum_of_digits;
        output = concat_str(6, to_str(num), " is NOT divisible by ", to_str(sum_of_digits), " (result: ", float_to_str(remainder), ")");
    }
    
    return output;
}
int to_int(char* num) {
    if(*(num) == '-') {
        int length = str_length(num);
        int inum = 0;
        for(int i = 1; i < length; i++) {
            int current_char = *(num+i) - 48;
            inum += (pow(10, length-i-1) * current_char);
        }
        return inum * -1;
    } else {
        int length = str_length(num);
        int inum = 0;
        for(int i = 0; i < length; i++) {
            int current_char = *(num+i) - 48;
            inum += (pow(10, length-i-1) * current_char);
        }
        return inum;       
    }
}
int main(int argc, char **argv) {
    printf("%s\n", is_divisible(151));
    return 0;
}