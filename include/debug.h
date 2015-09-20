#ifndef DEBUG_H
#define DEBUG_H

#include <stdio.h>

#define TEST(EXP)	do {\
						printf("test " #EXP ":\t%s\n",\
								EXP ? "PASS" : "FAILED");\
					} while(0)

#endif
