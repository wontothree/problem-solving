//
// Created by Kevin Liam on 2023/07/05.
//
#include <iostream>
using namespace std;

int main(void) {
    int a, b, plus, minus, multiply, divide, remain;

    std::cin >> a >> b;

    plus = a + b;
    minus = a - b;
    multiply = a * b;
    divide = a / b;
    remain = a % b;

    std::cout << plus << std::endl << minus << std::endl << multiply << std::endl << divide << std::endl << remain;
}