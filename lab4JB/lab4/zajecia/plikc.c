#include <stdio.h>

extern int sum(int a, int b);

int main()
{
  int a = 2;
  int b = 3;

  printf("%d + %d = %d\n", a, b, sum(a,b));  

  return 0;
}
