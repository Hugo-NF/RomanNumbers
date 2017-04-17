#include "module.h"
#include <gtest/gtest.h>

/**
	This file intends only to test the functions conteined in module.c/.h files.
	\n Here we are using the GoogleTest test framework.
*/
int main(int argc, char **argv){
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
