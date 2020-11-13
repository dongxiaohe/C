#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *sum(void *arg)
{
  char *textArg = (char *)arg;
  long long limit  = atoll(textArg);
  long long sum = 0;
  for (int i = 1; i <= limit; i++) {
    sum += i;
  }
  printf("the argument is %lld  \n", sum);

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
