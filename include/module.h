#ifndef MODULE_H
#define MODULE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define input_error -1
#define ptr_error NULL
#define max_number 3999

/**
    void lowercase (char *);
    \n This function puts all characters of the parameter string in lowercase.
    \n It's return type is void, since it modifies the string by reference.

*/
void lowercase(char *);

/**
    void uppercase (char *);
    \n This function puts all characters of the parameter string in uppercase.
    \n It's return type is void, since it modifies the string by reference.

*/
void uppercase(char *);

/**
    int* convert_arabic(char*);
    \n This function receives a string and returns an array of integers, corresponding to the direct conversion of the symbols of the roman number.
    \n If in the parameter string exists an unknown symbol, the function returns NULL (ptr_error).
    \n WARNING: this function is protected only against inputs with unknown symbols, since it was not designed to be a standalone function. Wrong combinations of regular symbols will be converted.
    \n WARNING: The user of this function must deallocate the memory under the returned pointer.
*/
int* convert_arabic(char *);

/**
    int compute_arabic(int *);
    \n This function receives an array of integers, resulting from the conversion of the symbols in the convert_arabic function,
    \n and calculates and returns an integer holding the resulting arabic number.
    \n WARNING: this function does not have any protection from wrong inputs, since it was not designed to be a standalone function. 
*/
int compute_arabic(int *);

/**
    int convert_roman(int, char *);
    \n This function receives a integer, representing the arabic number to be converted, and a string, to be manipulated by reference.
    \n WARNING: this function does not have any protection from wrong inputs, since it was not designed to be a standalone function.
*/
void convert_roman(int, char*);

/**
    int roman_to_arabic(char *);
    \n This function combines all the previous functions to correctly make the convertion from roman numbers to arabic numbers, preventing all mistakes related to wrong inputs.
    \n It receives a string holding the roman number to be converted.
    \n The function returns -1 (input_error) if the input roman number is invalid.
    \n Otherwise, it returns the number (int) equivalent to the input.
*/
int roman_to_arabic(char *);

/**
    char* arabic_to_roman(int);
    \n This function combines all the previous functions to correctly make the convertion from arabic numbers to roman numbers, preventing all mistakes related to wrong inputs.
    \n It receives a integer holding the arabic number to be converted.
    \n The function returns NULL (ptr_error) if the input arabic number is invalid.
    \n Otherwise, it returns the string (char*) with the roman number equivalent to the input.
*/
char* arabic_to_roman(int);


#endif // MODULE
