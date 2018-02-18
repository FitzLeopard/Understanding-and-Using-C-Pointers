#include<stdio.h>
#include<stdlib.h>

int * pi = (int*) malloc(sizeof(int));						//Problem

void staticpointinit(void)
{
	static int* pi = malloc(sizeof(int));					//Problem

	free(pi);
}

int main()
{
	free(pi);

	return 0;

}
