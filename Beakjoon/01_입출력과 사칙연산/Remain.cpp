//
// Created by Kevin Liam on 2023/07/12.
//
#include <iostream>

using namespace std;

int main(void) {
    int a, b, c, l, m, n, o;
    std::cin >> a >> b >> c;
    l = (a + b) % c;
    m = (a % c + b % c) % c;
    n = (a * b) % c;
    o = ((a % c) * (b % c)) % c;
    std::cout << l << std::endl << m << std::endl << n << std::endl << o << std:: endl;
    return 0;
}