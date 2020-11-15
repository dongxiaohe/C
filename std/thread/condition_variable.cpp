#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::string greeting;
std::mutex m;
std::condition_variable cv;
bool ready = false;
bool processed = false;

void worker_thread()
{
  std::cout << "thread is starting " << std::endl;
  std::unique_lock<std::mutex> lock(m);
  cv.wait(lock, []{return ready;});
  
  greeting += " by worker thread";
  processed = true;
  lock.unlock();
  cv.notify_one();
}

int main()
{
  std::thread worker(worker_thread);
  greeting = "greeting";
  std::cout << "main thread is starting " << std::endl;

  ready = true;
  cv.notify_one();
  std::unique_lock<std::mutex> lock(m);
  cv.wait(lock, []{return processed;});

  std::cout << greeting << std::endl;

  worker.join();
}
