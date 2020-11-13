#include <stdio.h>

// void* can represent any type
int add(void *a, int *b)
{
  int* inta = (int *)a;
  return *inta + *b;
}

int doStuff()
{
  return 3;
}

int main(int argc, char** argv)
{
  int b = 3;
  printf("the total %d \n", add(&doStuff, &b));
}
