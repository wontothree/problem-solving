# Development Log

*11382*

암기

https://qhrhksgkazz.tistory.com/230

*10171 cat* printing special letter in C

% -> %%, \ -> \\, " -> \"

*10952*

Before

```c
#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int nums1[100], nums2[100];

    bool is_continue = true;
    int last_index = 0;
    while (is_continue) {
        scanf("%d %d", &nums1[last_index], &nums2[last_index]);

        if (nums1[last_index] == 0 && nums2[last_index] == 0) {
            is_continue = false;
        }

        last_index++;
    }

    for (int i = 0; i < last_index - 1; i++) {
        printf("%d\n", nums1[i] + nums2[i]);
    }

    return 0;
}
```

After

```c
#include <stdio.h>

int main(void) {
    int nums1[100], nums2[100];

    int last_index = 0;
    while (1) {
        scanf("%d %d", &nums1[last_index], &nums2[last_index]);

        if (nums1[last_index] == 0 && nums2[last_index] == 0) {
            break;
        }

        last_index++;
    }

    for (int i = 0; i < last_index; i++) {
        printf("%d\n", nums1[i] + nums2[i]);
    }

    return 0;
}
```

*3052*

배열에서 서로 다른 수의 개수

[1, 2, 3, 4, 5, 5, 5, 6, 7, 8]

*11720*

to transform type char '5' to int '5'

```c
char ch = '5';
int num = ch - '0';
```

*10809*

while 문에서 break으로 빠져나오지 않고 조건을 불만족하여 빠져나온 경우에만 조건 걸기. flag를 이용한다.

```c
int j = 0;
int found = 0;
while (word[j] != '\0') {
    if (word[j] == i) {
        break;
    }
    j++;
}

if (word[j] == '\0') {
    j = -1;
}
```

*2908* 문자열 to int

```c
#include <stdlib.h>

$[variable] = atoi($[variable])
```
