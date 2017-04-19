#include "module.h"

void lowercase (char *romans){
    int i;
    for(i=0; i<strlen(romans); i++){
        romans[i] = tolower(romans[i]);
    }
}

void uppercase (char *romans){
    int i;
    for(i=0; i<strlen(romans); i++){
        romans[i] = toupper(romans[i]);
    }
}

int* convert_arabic (char *roman){
    int i;
    int *numbers;

    numbers = (int *) malloc((strlen(roman)+1)*sizeof(int));
    numbers[0] = strlen(roman);

    for(i=1; i<=strlen(roman); i++){
        switch(roman[i-1]){
            case 'i':
                numbers[i] = 1;
                break;
            case 'v':
                numbers[i] = 5;
                break;
            case 'x':
                numbers[i] = 10;
                break;
            case 'l':
                numbers[i] = 50;
                break;
            case 'c':
                numbers[i] = 100;
                break;
            case 'd':
                numbers[i] = 500;
                break;
            case 'm':
                numbers[i] = 1000;
                break;
            default:
                free(numbers);
                return ptr_error;
        }
    }

    return numbers;
}

int compute_arabic (int *conversion){
    int number = 0;
    int i;

    for(i=conversion[0]; i>0; i--){
        if(i==1 || conversion[i] <= conversion[i-1]){
            number +=conversion[i];
        }
        else if(conversion[i]>conversion[i-1]){
            number +=(conversion[i] - conversion[i-1]);
            i--;
        }
    }
    return number;
}

void convert_roman(int arabic, char *result_roman){
    char *hundreds[] = {"", "c", "cc", "ccc", "cd", "d", "dc", "dcc", "dccc", "cm"};
    char *dozens[]  = {"", "x", "xx", "xxx", "xl", "l", "lx", "lxx", "lxxx", "xc"};
    char *units[] = {"", "i", "ii", "iii", "iv", "v", "vi", "vii", "viii", "ix"};
    int   size[] = { 0, 1, 2, 3, 2, 1, 2, 3, 4, 2};

    while (arabic >= 1000){
        *result_roman++ = 'm';
         arabic -= 1000;
    }

    strcpy (result_roman, hundreds[arabic / 100]);
    result_roman += size[arabic / 100];
    arabic = arabic % 100;
    strcpy (result_roman, dozens[arabic / 10]);
    result_roman += size[arabic / 10];
    arabic = arabic % 10;
    strcpy (result_roman, units[arabic]);
    result_roman += size[arabic];
}
