# Instructions

### P39
The memory allocated will be **aligned** according
to the pointer's **data type**. For example, a four-byte
integer would be allocated on an address boundary
evenly divisible by four.

So far, I have to say, the rule is **true**.

Test program is in the source file **P39.c**.

### P42
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
But this trick cannot apply to the global pointer since `global variables
are declared outside of a function and excutable code, such as the assignment
statement, must be inside of a function.` as the **book** says. But what it
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
The example is in the source file **P42**\_**solution.c**.

### P44
#### Less
When we use **realloc** function to allocate memory---`realloc(void * ptr, size_t size)`,
the size may be smaller than the original size of previously allocated memory. When this 
happens, the excess memory will be **returned** to the heap, but there is no guarantee that 
the excess memory will be **cleared**. And even the returned excess memory can be accessed 
as if it is legal.

The example is in the source file **P44**\_**less.c**.
#### More
When we use **realloc** function to allocate memory, there is also the chance that the size 
may be larger than the original size of previously allocated memory. When this happens, 
if possible, memory will be allocated right after the current region. Otherwise, `the current
 region will not be changed and memory will be allocated from a different region.` **as the book
 says**. But actually, the current region seems to be changed in an **extremely weired** way, and
 I have not thought of any explanation **why** this happens so far.

The example is in the source file **P44**\_**more.c**.
