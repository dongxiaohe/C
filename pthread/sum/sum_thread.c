#include <stdio.h>
#include <pthread.h>

void *sum(void *arg)
{
  char *textArg = (char *)arg;
  printf("the argument is %s \n", textArg);

  pthread_exit(0);
}

int main(int argc, char **argv)
{
  pthread_t tid; 
  pthread_attr_t attr;
  pthread_attr_init(&attr);

  int status = pthread_create(&tid,  &attr, sum, argv[1]);

  printf("pthread_create status is %d \n", status);
  
  pthread_join(tid, NULL);

  return 0;
}
