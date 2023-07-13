//
// Created by Kevin Liam on 2023/07/12.
//
#include <iostream>
#include <cstdlib>

using namespace std;

// 몫과 나머지를 이용한 풀이
//int main(void) {
//    int a, b, n1, n2, n3, n4;
//    std::cin >> a >> b;
//    n1 = a * (b % 10);
//    n2 = a * (b / 10 % 10);
//    n3 = a * (b / 100);
//    n4 = a * b;
//    std::cout << n1 << std::endl << n2 << std::endl << n3 << std::endl << n4;
//
//    return 0;
//}

// 문자열을 이용한 풀이
int main(int argc, char const *argv[]) {
    int A;
    char B[4];

    std::cin >> A;
    std::cin >> B;

    cout << A * (B[2] - '0') << "\n";
    cout << A * (B[1] - '0') << "\n";
    cout << A * (B[0] - '0') << "\n";
    cout << A * atoi(B) << "\n";

    return 0;
}
