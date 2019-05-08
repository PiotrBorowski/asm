#include <stdio.h>

extern unsigned long long fibb(unsigned long long a);

int main()
{
 unsigned long long arg;
 scanf("%llu", &arg);
 unsigned long long wynik = fibb(arg);
 printf("%llu\n", wynik);

 return 0;
}
