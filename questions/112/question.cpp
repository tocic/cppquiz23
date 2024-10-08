#include <iostream>
#include <utility>

struct A
{
    A() { std::cout << "1"; }
    A(const A&) { std::cout << "2"; }
    A(A&&) { std::cout << "3"; }
};

struct B
{
    A a;
    B() { std::cout << "4"; }
    B(const B& b) : a(b.a) { std::cout << "5"; }
    B(B&& b) : a(b.a) { std::cout << "6"; }
};

int main()
{
    B b1;
    B b2 = std::move(b1);
}