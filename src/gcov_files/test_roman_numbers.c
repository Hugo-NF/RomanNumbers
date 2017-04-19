#include "module.h"
#include <gtest/gtest.h>

/**
	Test 1 - lowercase
	\n This test compares the resulting string with the input string in lowercase characters
	\n There are 3 possible inputs: 
		\n\t 1. String with all character in uppercase
		\n\t 2. String with mixed uppercase and lowercase characters
		\n\t 3. String is already in lowercase
	\n Passing this test means that the function successfully converts or keeps a string in lowercase
*/
TEST(lowercase_function, comparing_IO){
	char string_tests[20];
	
	strcpy(string_tests, "TEST_LOWER");
	lowercase(string_tests);
	EXPECT_EQ(0, strcmp("test_lower", string_tests));

	strcpy(string_tests, "TeSt_lOwEr");
	lowercase(string_tests);
	EXPECT_EQ(0, strcmp("test_lower", string_tests));

	strcpy(string_tests, "test_lower");
	lowercase(string_tests);
	EXPECT_EQ(0, strcmp("test_lower", string_tests));
}

/**
	Test 2 - uppercase
	\n This test compares the resulting string with the input string in uppercase characters
	\n There are 3 possible inputs: 
		\n\t 1. String with all character in lowercase
		\n\t 2. String with mixed uppercase and lowercase characters
		\n\t 3. String is already in uppercase
	\n Passing this test means that the function successfully converts or keeps a string in uppercase
*/
TEST(uppercase_function, comparing_IO){
	char string_tests[20];
	
	strcpy(string_tests, "test_upper");
	uppercase(string_tests);
	EXPECT_EQ(0, strcmp("TEST_UPPER", string_tests));

	strcpy(string_tests, "TeSt_uPpEr");
	uppercase(string_tests);
	EXPECT_EQ(0, strcmp("TEST_UPPER", string_tests));

	strcpy(string_tests, "TEST_UPPER");
	uppercase(string_tests);
	EXPECT_EQ(0, strcmp("TEST_UPPER", string_tests));
}

/**
	Test 3 - convert_arabic
	\n This function intends to generate an array with the arabic numbers corresponding to the roman symbols given in a string
	\n WARNING: this function is protected only against inputs with unknown symbols, since it was not designed to be a standalone function. Wrong combinations of regular symbols will be converted. 
		\n\t The first test situation analises the behavior if the function receives a string with incoherent symbols
		\n\t All other tests analises the array generated given a regular input.
	\n Passing this test means that the function successfully converts the symbols from the string to a array of integers.
*/
TEST(convert_arabic_function, all_cases){
	char string_tests[20];
	int *numbers;

	strcpy(string_tests, "ax");
	EXPECT_EQ(NULL, convert_arabic(string_tests));


	strcpy(string_tests, "iv");
	numbers = (int *) convert_arabic(string_tests);

	EXPECT_EQ(1, numbers[1]);
	EXPECT_EQ(5, numbers[2]);


	strcpy(string_tests, "dcccxx");
	numbers = (int *) convert_arabic(string_tests);

	EXPECT_EQ(500, numbers[1]);
	EXPECT_EQ(100, numbers[2]);
	EXPECT_EQ(100, numbers[3]);
	EXPECT_EQ(100, numbers[4]);
	EXPECT_EQ(10, numbers[5]);
	EXPECT_EQ(10, numbers[6]);

	strcpy(string_tests, "mccclxxxviii");
	numbers = (int *) convert_arabic(string_tests);

	EXPECT_EQ(1000, numbers[1]);
	EXPECT_EQ(100, numbers[2]);
	EXPECT_EQ(100, numbers[3]);
	EXPECT_EQ(100, numbers[4]);
	EXPECT_EQ(50, numbers[5]);
	EXPECT_EQ(10, numbers[6]);
	EXPECT_EQ(10, numbers[7]);
	EXPECT_EQ(10, numbers[8]);
	EXPECT_EQ(5, numbers[9]);
	EXPECT_EQ(1, numbers[10]);
	EXPECT_EQ(1, numbers[11]);
	EXPECT_EQ(1, numbers[12]);

	free(numbers);

}

/**
	Test 4 - compute_arabic
	\n This function intends to give the resulting arabic number after receiving the array generated by convert_arabic function
	\n WARNING: this function does not have any protection from wrong inputs, since it was not designed to be a standalone function.
		\n\t All tests analises the number generated given a regular input
	\n Passing this test means that the function successfully calculates the arabic number given the array of integers generated by convert_arabic.	
*/
TEST(compute_arabic_function, all_cases){

	int index_array1[] = {12, 1000, 100, 100, 100, 50, 10, 10, 10, 5, 1, 1, 1};
	int index_array2[] = {2, 10, 10};
	int index_array3[] = {6, 500, 100, 100, 100, 10, 10};
	int index_array4[] = {2, 1, 10};

	EXPECT_EQ(1388, compute_arabic(index_array1));
	EXPECT_EQ(20, compute_arabic(index_array2));
	EXPECT_EQ(820, compute_arabic(index_array3));
	EXPECT_EQ(9, compute_arabic(index_array4));
}

/**
	Test 5 - convert_roman
	\n This function intends to convert an integer (arabic number) in a string with the correspondent roman number
	\n WARNING: this function does not have any protection from wrong inputs, since it was not designed to be a standalone function.
		\n\t All tests analises the string generated given a regular input
	\n Passing this test means that the function successfully alterates, by reference, the parameter string. 
*/
TEST(convert_roman, all_cases){
	char string_tests[20];

	convert_roman(20, string_tests);
	EXPECT_EQ(0, strcmp("xx", string_tests));

	convert_roman(1388, string_tests);
	EXPECT_EQ(0, strcmp("mccclxxxviii", string_tests));

	convert_roman(1550, string_tests);
	EXPECT_EQ(0, strcmp("mdl", string_tests));

	convert_roman(9, string_tests);
	EXPECT_EQ(0, strcmp("ix", string_tests));
}

/**
	Test 6 - roman_to_arabic
	\n This function combines all the previous functions to correctly make the convertion from roman numbers to arabic numbers, preventing all mistakes related to wrong inputs.
		\n\t The first test situation analises the behavior if the function receives a NULL char pointers or wrong combinations of symbols.
		\n\t All other tests analises the integer generated given a regular input
	\n Passing this test means that the function successfully converts the number.
*/
TEST(roman_to_arabic, all_cases){
	char string_tests[20];

	EXPECT_EQ(-1, roman_to_arabic(NULL));

	strcpy(string_tests, "axx");
	EXPECT_EQ(-1, roman_to_arabic(string_tests));

	strcpy(string_tests, "xxixx");
	EXPECT_EQ(-1, roman_to_arabic(string_tests));

	strcpy(string_tests, "iiii");
	EXPECT_EQ(-1, roman_to_arabic(string_tests));

	strcpy(string_tests, "xxixx");
	EXPECT_EQ(-1, roman_to_arabic(string_tests));

	strcpy(string_tests, "xlx");
	EXPECT_EQ(-1, roman_to_arabic(string_tests));

	strcpy(string_tests, "vx");
	EXPECT_EQ(-1, roman_to_arabic(string_tests));

	strcpy(string_tests, "ix");
	EXPECT_EQ(9, roman_to_arabic(string_tests));

	strcpy(string_tests, "xxx");
	EXPECT_EQ(30, roman_to_arabic(string_tests));

	strcpy(string_tests, "mdl");
	EXPECT_EQ(1550, roman_to_arabic(string_tests));

	strcpy(string_tests, "mccclxxxviii");
	EXPECT_EQ(1388, roman_to_arabic(string_tests));

	strcpy(string_tests, "mmdxii");
	EXPECT_EQ(2512, roman_to_arabic(string_tests));

}

/**
	Test 7 - roman_to_arabic
	\n This function combines all the previous functions to correctly make the convertion from arabic numbers to roman numbers, preventing all mistakes related to wrong inputs.
		\n\t The first test situation analises the behavior if the function receives a negative number.
		\n\t All other tests analises the string generated given a regular input
	\n Passing this test means that the function successfully converts the number.
*/
TEST(arabic_to_roman, all_cases){
	
	EXPECT_EQ(NULL, arabic_to_roman(-1));
	EXPECT_EQ(0, strcmp("IX", arabic_to_roman(9)));
	EXPECT_EQ(0, strcmp("XXXI", arabic_to_roman(31)));
	EXPECT_EQ(0, strcmp("IV", arabic_to_roman(4)));
	EXPECT_EQ(0, strcmp("MDL", arabic_to_roman(1550)));
	EXPECT_EQ(0, strcmp("MCCCLXXXVIII", arabic_to_roman(1388)));
	EXPECT_EQ(0, strcmp("MMDXII", arabic_to_roman(2512)));
	EXPECT_EQ(0, strcmp("LIX", arabic_to_roman(59)));
}

/**
	This file intends only to test the functions conteined in module.c/.h files.
	\n Here we are using the GoogleTest test framework.
*/
int main(int argc, char **argv){
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
