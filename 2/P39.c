/****************************************************
 The memory allocated will be aligned according
 to the pointer's data type. For example, a four-byte
 integer would be allocated on an address boundary
 evenly divisible by four.
 ****************************************************/

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int * p_int = malloc(sizeof(int));
	double * p_double = malloc(sizeof(double));
	char c;

	while (scanf("%c", &c) == 1) {
		printf("%s%i\n%s%i\n%s%i\n%s%i\n",													//print the address of the pointer and the size of the type
				"The address of    int:", (int)p_int,
				"The    size of    int:", sizeof(int),
				"The address of double:", (int)p_double,
				"The    size of double:", sizeof(double));
		if ((int)p_int % sizeof(int) == 0 && (int)p_double % sizeof(double) == 0) {			//test the address and the size and print the result
			puts("Yes, the rule is true!");
		}
		else {
			puts("No, there does exist an exception!");
			break;
		}
		free(p_int);
		free(p_double);
		p_int = malloc(sizeof(int));
		p_double = malloc(sizeof(double));
	}

	free(p_int);
	free(p_double);																			//release the memory

	return 0;
}
