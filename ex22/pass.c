#include <stdio.h>

void reference(int *x, int *y) {
  printf("lets swap\n");
  int *tmp;
  *tmp = *x;
  *x = *y;
  *y = *tmp;
}

void value(int x, int y)
{
  int tmp = x;
  x = y;
  y = tmp;
}

int main(int argc, char *argv[])
{
  int num = 3;
  int num2 = 4;
  printf("x is %d\n", num);
  printf("y is %d\n", num2);
  value(num, num2);
  printf("swap by value\n");
  printf("x is now %d\n", num);
  printf("y is now %d\n", num2);

  reference(&num, &num2);
  printf("swap by reference\n");
  printf("x is now %d\n", num);
  printf("y is now %d\n", num2);
  return 0;
}

