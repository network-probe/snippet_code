#include <iostream>

class SimpleClass {
 public:
    /**
     * const method 의 경우 해당 Object 내의 멤버 변수 변경 불가능
    */
    void method_const() const {} 

    /**
     * 일반 멤버 함수
    */
    int method() { return var; }

    /**
     * method의 오버로딩은 아니다. 즉 상위 method와 method() const는 구분 불가능..
     * 아래와 같은 경우는 해당 멤버함수의 호출의 리턴값은 오로지 const에만 담을 수 있다.
     * 즉 상기 일반 멤버 함수와 같이 사용 불가능...(오버로딩 불가능...)
    */
    const int& method() const { return var; }

    void method(int p) { var = p; }
    void method(const int& p) { var = p; }

 private:
    int var = 2;
};

int main() {
    SimpleClass s;

    // const auto& a = s.method();
    // a = 2;
    
    // s.method_const();
    return 0;
}