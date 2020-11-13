#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

long long total = 0;

void *sum(void *arg)
{
  char *textArg = (char *)arg;
  long long limit  = atoll(textArg);
  for (int i = 1; i <= limit; i++) {
    total += i;
  }
  printf("the argument is %lld  \n", total);

  pthread_exit(0);
}

int main(int argc, char **argv)
{
  int num = argc - 1;
  pthread_t tids[num]; 

  for(int i = 0; i < num; i++) {
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    int status = pthread_create(&tids[i],  &attr, sum, argv[i + 1]);
    printf("pthread_create status is %d \n", status);
  }

  for(int i = 0; i < num; i++) {
    pthread_join(tids[i], NULL);
  }

  return 0;
}
