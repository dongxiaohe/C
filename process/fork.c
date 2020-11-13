#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
  printf("pid is %d \n", (int)getpid());
  pid_t newpid = fork();
  printf("forked pid is %d \n", (int)newpid);
  printf("new pid is %d \n", (int)getpid());
}
