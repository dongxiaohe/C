#include <queue>
#include <iostream>

template<typename T> void print_queue(T& q) {
  while(!q.empty()) {
    std::cout << q.top() << " ";
    q.pop();
  }
}

int main() {
  auto cmp = [](int a, int b) {
    return (a ^ 1) < (b ^ 1);
  };
  std::priority_queue<int, std::vector<int>, decltype(cmp)> q(cmp);
  for(int n : {1,8,5,6,3,4,0,9,7,2})
    q.push(n);

  print_queue(q);
}
