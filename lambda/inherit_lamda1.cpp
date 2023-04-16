#include <functional>
#include <type_traits>
#include <iostream>

template<typename L1, typename L2>
struct S : L1, L2 {
    S(L1 l1, L2 l2) : L1(std::move(l1)), L2(std::move(l2)) {}

    using L1::operator();
    using L2::operator();

    int operator()() {
        return 18;
    }
};

// This is c++11
template<typename L1, typename L2>
auto make_combined(L1&& l1, L2&& l2) {
    return S<std::decay_t<L1>, std::decay_t<L2>>(std::forward<L1>(l1), std::forward<L2>(l2));
}

int main() {
    auto l1 = [](){ return 4; };
    auto l2 = [](int i){ return i * 10; };

    // This is c++11
    auto combined_c11 = make_combined(l1, l2);

    // This is c++17
    auto combined_c17 = S(l1, l2);

    std::cout << combined_c11() << '\n';
    std::cout << combined_c11(4) << '\n';

    std::cout << combined_c17() << '\n';
    std::cout << combined_c17(4) << '\n';    
}

