/* NOTE
04번 문제
    - 시간 제한 : 2초
    - 메모리 제한 : 256MB

05번 문제
    - 시간 제한 : 5초
    - 메모리 제한 : 8MB

04번 문제는 시간 복잡도에 집중하는 반면 05번 문제는 공간 복잡도에 집중한다.
- num \leq 10^7
- 하지만 실제로 들어오는 수는 10,000 이하의 값을 갖는다.

단위
- kilobyte (KB) = 1024 byte
- megabyte (MB) = 1024 kilobyte (= 1024 x 1024 kilobyte)

int : 4byte

int num을 선언 시 4byte x 10^7 / (1024 x 1024) = 38.15 megabyte

short로 선언하더라도 메모리 초과가 발생한다. 즉, 자료구조로는 해결할 수 없고 근본적으로 다른 정렬 알고리즘을 사용해야 한다. 

-> 계수 정렬 (counting sorting).
*/
#include <stdio.h>

int main(void) {
    // input
    int size;
    scanf("%d", &size);

    int max = 10000;

    // initialize array
    int arr[max + 1];
    for (int i = 0; i < max + 1; i++)
        arr[i] = 0;

    // input
    int tmp = 0;
    for (int i = 0; i < size; i++) {
        scanf("%d", &tmp);
        arr[tmp]++;
    }

    for (int i = 0; i < max + 1; i++)
        for (int j = 0; j < arr[i]; j++)
            printf("%d ", i);

    return 0;
}