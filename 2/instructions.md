#Instructions

###P39
The memory allocated will be **aligned** according
to the pointer's **data type**. For example, a four-byte
integer would be allocated on an address boundary
evenly divisible by four.

So far, I have to say, the rule is **true**.

###P42
We cannot use *malloc* function to initialize static and global
pointers. Code like this:
```
static int *pi = malloc(sizeof(int));
```
is absolutely illegal and will generate a compile-time error message:
<font color = red>**error**</font>:initializer element is not constant
The example is in the source file **P42.c**.

But there is a solution, we can use a separate assignment to allocate 
memory to the variable as follows:
```
static int *pi;
pi = (int*) malloc(sizeof(int));
```
But this trick cannot apply to the global pointer since *global variables
are declared outside of a function and excutable code, such as the assignment
statement, must be inside of a function.* as the **book** says. But what it
means is that we cannot use such code:
```
#include<stdio.h>
#include<stdlib.h>

int* pi;
pi = malloc(sizeof(int));

int main()
{
	...
}
```

But there does exist a solution. We can use an assignment statement at the beginning
of the main function to solve this:
```
#include<stdio.h>
#include<stdlib.h>

int* pi;

int main()
{
	pi = malloc(sizeof(int));
	...
}
```
