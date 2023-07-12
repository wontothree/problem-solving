//
// Created by Kevin Liam on 2023/07/05.
//
#include <iostream>
#include <iomanip>

using namespace std;

int main(void) {
    int a, b;
    double c;

    std::cin >> a >> b;

    c = (double)a / b;

    std::cout << std::setprecision(20) << std::fixed << c << std::endl;

    return 0;
}