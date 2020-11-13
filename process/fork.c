#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{
  printf("pid is %d \n", (int)getpid());
  pid_t cpid = fork();
  if (cpid < 0) {
    perror("something went wrong \n");
  } else if (cpid == 0) {
    printf("I am the child process \n");
    sleep(5);
    exit(0);
  }
  printf("forked pid is %d and waiting it finished \n", (int)cpid);
  wait(NULL);
  printf("all done \n");
}
