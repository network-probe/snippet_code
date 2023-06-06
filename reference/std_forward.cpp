#include <utility>

template <class T>
void foo(T&& arg) {
  std::cout << "rvalue ref\n";
}

template <class T>
void foo(T& arg) {
  std::cout << "lvalue ref\n";
}

template <class T>
void wrapper(T&& arg) {
  foo(arg);  // alway an lvalue

  // arg가 lvalue 이면 lvalue reference, arg가 rvalue reference이면 rvalue
  // reference(move parameter)
  foo(std::forward<T>(arg));  // Forward as lvalue or as rvalue, depending on T
}

int main() {
  wrapper(1);

  int i = 1;
  wrapper(i);

  // 아래것은 왜 실패인지 아직 이해 못함
  // wrapper<int>(i);
}
