#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct total_struct {
  long long limit;
  long long result;
};

void *sum(void *arg)
{
  struct total_struct *total = (struct total_struct*) arg;
  total->result = 0;
  for (int i = 1; i <= total->limit; i++) {
    total->result += i;
  }
  printf("the total sum to the argument is %lld  \n", total->result);

  pthread_exit(0);
}

int main(int argc, char **argv)
{
  if (argc < 2) {
    printf("wrong usage, please provide num1, num2, num3 \n");
    return;
  }
  int num = argc - 1;
  pthread_t tids[num]; 
  struct total_struct total[num];

  for(int i = 0; i < num; i++) {
    pthread_attr_t attr;
    pthread_attr_init(&attr);

    total[i].limit = atoll(argv[i + 1]);
    int status = pthread_create(&tids[i],  &attr, sum, &total[i]);
    if (status != 0) {
      printf("something went wrong, pthread_create status is %d \n", status);
    }
  }

  for(int i = 0; i < num; i++) {
    pthread_join(tids[i], NULL);
  }

  return 0;
}
