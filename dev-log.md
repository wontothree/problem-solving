# Development Log

*11382 Runt Jeongmin*

암기

https://qhrhksgkazz.tistory.com/230

*10171 cat* printing special letter in C

% -> %%, \ -> \\, " -> \"

*10952 A + B - 5*

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
