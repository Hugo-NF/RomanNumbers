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

}
