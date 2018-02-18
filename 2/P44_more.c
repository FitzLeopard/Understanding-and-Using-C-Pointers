#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char *string1, *string2;

	string1 = malloc(16 * sizeof(char));
	strcpy(string1, "0123456789AB");
	string2 = (char *)realloc(string1, 138750);						//very large memory, force the runtime environment to start from a new region
	printf("string1 Value: %p [%s]\n", (void *)string1, string1);
	printf("string2 Value: %p [%s]\n", (void *)string2, string2);

	return 0;
}
