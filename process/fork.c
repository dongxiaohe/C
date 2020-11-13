#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
  printf("pid is %d \n", (int)getpid());
}
