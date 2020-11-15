#include <thread>
#include <iostream>
#include <condition_variable>
#include <mutex>

struct critical_data {
  std::mutex m; 
};

void worker_thread(long long count, critical_data& data)
{
  std::unique_lock<std::mutex> ik(data.m);
  for(;;) {
    printf("thread starting %lld \n", count);
    count++;
  }
}
int main()
{
  long long count = 0; 
  critical_data data;
  std::thread worker1([&]{
    worker_thread(count, data);
  });
  std::thread worker2([&]{
    worker_thread(count, data);
  });

  worker1.join();
  worker2.join();
}
