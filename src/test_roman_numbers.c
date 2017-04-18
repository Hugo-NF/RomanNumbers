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
	This file intends only to test the functions conteined in module.c/.h files.
	\n Here we are using the GoogleTest test framework.
*/
int main(int argc, char **argv){
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
