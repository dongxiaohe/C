#include <iostream>
#include <queue>

template<typename T> void print_queue(T& q) {
  while(!q.empty()) {
    std::cout << q.top() << " ";
    q.pop();
  }
}
int main() {
  std::priority_queue<int> q;

  for(int i : {1, 3, 7, 6, 5, 9, 10, 30, 15}) {
    q.push(i);
  }
  print_queue(q);
}

