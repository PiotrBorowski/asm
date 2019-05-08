#include <stdio.h>

int main()
{
 unsigned long long arg,wynik;

 scanf("%llu", &arg);
 
 asm(
"movq $0, %%rax\n"
"movq $1, %%rcx\n"
"loop: addq %%rcx, %%rax\n"
"xchg %%rcx, %%rax\n"
"decq %%rbx\n"
"cmpq $1, %%rbx\n"
"jne loop\n"
"end: movq %%rcx, %%rax\n"
:"=a"(wynik)
:"b"(arg)

);

 printf("%llu\n", wynik);

 return 0;
}
