#include <stdio.h>
#include <pthread.h>

long long sum = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
void* pthread_func(void* args)
{
  int increment = *(int *) args;
  for(int i = 0; i < 5000000; i ++) {
    pthread_mutex_lock(&mutex);
    sum += increment;
    pthread_mutex_unlock(&mutex);
  }
  pthread_exit(NULL);
}
int main(int argc, char** argv)
{
  pthread_t pid1;
  int increment1 = 1;
  pthread_create(&pid1, NULL, pthread_func, &increment1);
  
  pthread_t pid2;
  int increment2 = -1;
  pthread_create(&pid2, NULL, pthread_func, &increment2);

  pthread_join(pid1, NULL); 
  pthread_join(pid2, NULL); 
  
  printf("the sum is %lld \n", sum);
}
