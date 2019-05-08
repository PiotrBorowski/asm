#include <stdio.h>
unsigned long long rdtsc();
int sum(int a, int b);

extern int number1;

int b = 4;
int c = 7;
int result = 0;

int main()
{
	printf("number1: %d \n", number1);
	int a = sum(2,3);
	printf("stamp: %llu\n", rdtsc());
	printf("stamp: %llu\n", rdtsc());
	printf("stamp: %llu\n", rdtsc());
	printf("sum: %d\n", a);

	asm(
		"addl %%ebx, %%ecx\n"
		"movl %%ecx, %%edx\n"
		:"=d"(result)
		: "c"(c), "b"(b)
	);
	printf("sum inline:%d\n", result);	

	b = 5;
	c = 8;
	asm(
		"addl %1, %2\n"
		"movl %2, %0\n"
		:"=g"(result)
		: "g"(c), "g"(b)
	);
	printf("sum inline:%d\n", result);

return 0;
}