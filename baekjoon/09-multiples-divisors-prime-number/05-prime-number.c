#include <stdio.h>
#include <stdbool.h>

int main(void) {
    // input
    int lower_bound, upper_bound;
    scanf("%d\n%d", &lower_bound, &upper_bound);

    // declare and initialize
    int prime_numbers[10000];
    int last = 0;
    for (int i = 0; i < 10000; i++) {
        prime_numbers[i] = 0;
    }

    for (int object_number = lower_bound; object_number <= upper_bound; object_number++) {
        bool is_prime_number = true;
        if (object_number == 1) {
            is_prime_number = false;
        }
        
        for (int j = 2; j < object_number; j++) {
            if (object_number % j == 0) {
                is_prime_number = false;
                break;
            }
        }

        if (is_prime_number) {
            prime_numbers[last] = object_number;
            last++;
        }
    }

    int prime_sum = 0;
    int prime_min = prime_numbers[0];
    for (int index = 0; index < last; index++) {
        if (prime_min >= prime_numbers[index]) {
            prime_min = prime_numbers[index];
        }

        prime_sum += prime_numbers[index];
    }

    if (prime_sum == 0) {
        printf("%d", -1);
    } else {
        printf("%d\n%d", prime_sum, prime_min);
    }

    return 0;
}