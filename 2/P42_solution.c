#include<stdio.h>
#include<stdlib.h>

int * pi;

void staticpointinit(void)
{
	static int* pi;
	pi = (int*) malloc(sizeof(int));		//Solution

	free(pi);
}

int main()
{
	pi = (int*) malloc(sizeof(int));		//Solution
	free(pi);

	return 0;

}
