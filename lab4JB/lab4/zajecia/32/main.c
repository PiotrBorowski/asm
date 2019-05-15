#include <stdio.h>

extern int fib(int a);
int a, wynik;
int main()
{	
	puts("Proszę podać liczbę: ");
	scanf("%d", &a);
	printf("%d\n", fib(a));
	return 0;
}
