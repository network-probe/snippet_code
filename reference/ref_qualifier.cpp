#include <iostream>

class S {
 public:
    void bar() & {
        std::cout << "lvalue ref qualifier\n";
    }

    void bar() && {
        std::cout << "rvalue ref qualifier\n";
    }
};

class Example {
 public:
    std::string& ret() & { return str; }
    const std::string& ret() const & { return str; }

    std::string&& ret() && { return std::move(str); }

 private:
    std::string str = "test string";
};

int main() {
    {
        S s;
        s.bar();    // called lvalue ref ...

        S{}.bar();  // called rvalue ref ...
    }

    {
        Example e;
        auto r = e.ret();
        std::cout << r << " " << e.ret() << '\n';
    }

    return 0;
}