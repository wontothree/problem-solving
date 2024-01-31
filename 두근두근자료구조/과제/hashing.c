#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUCKET_SIZE 11
#define SLOT_SIZE 3

typedef struct Record {
    int key;
    char value[128];
} Record;

Record ht[BUCKET_SIZE][SLOT_SIZE];

void init_map() {
    int bucket, slot;
    for (bucket = 0; bucket < BUCKET_SIZE; bucket++)
        for (slot = 0; slot < SLOT_SIZE; slot++) {
            ht[bucket][slot].key = 0;
            ht[bucket][slot].value[0] = '\0';
        }
}

void print_map() {
    int bucket, slot;
    for (bucket = 0; bucket < BUCKET_SIZE; bucket++) {
        printf("[%2d] ", bucket);
        for (slot = 0; slot < SLOT_SIZE; slot++)
            printf("%2d : %20s  ", ht[bucket][slot].key, ht[bucket][slot].value);
        printf("\n");
    }
}

void add_record(int key, char* value) {
    int index, inc = 0, j;
    index = key % BUCKET_SIZE;

    while (1) {
        // duplication check
        for (j = 0; j < SLOT_SIZE; j++)
            if (ht[index][j].key == key) {
                printf("[%4d] 탐색 키가 중복되었습니다.\n", key);
                return;
            }

        // overflow
        if (ht[index][SLOT_SIZE - 1].key != 0) {
            printf("[%4d] 저장 시 인덱스 %d bucket에서 overflow가 발생합니다.\n", key, index);
            inc += 1;
            index = (index + inc * inc) % BUCKET_SIZE;
        } else
            break;

        // saturation check
        int cnt = 0;
        for (j = 0; j < BUCKET_SIZE; j++)
            if (ht[j][SLOT_SIZE - 1].key != 0)
                cnt += 1;

        if (cnt == BUCKET_SIZE) {
            printf("[%4d] 테이블이 포화 상태입니다.\n", key);
            return;
        }

        break;
    }

    for (j = 0; j < SLOT_SIZE; j++)
        if (ht[index][j].key == 0) {
            ht[index][j].key = key;
            strcpy(ht[index][j].value, value);
            return;
        }
}

void search_record(int key) {
    int index, inc, hashValue;
    hashValue = index = key % BUCKET_SIZE;

    while (ht[index][0].key != 0 || index == hashValue) {
        // 해당 버킷의 모든 슬롯을 확인
        for (int j = 0; j < SLOT_SIZE; j++) {
            if (ht[index][j].key == key) {
                printf("%2d 탐색 성공 ", key);
                printf("%2d : %s\n", index, ht[index][j].value);
                return; // 함수 종료
            }
        }

        inc += 1;
        index = (index + inc * inc) % BUCKET_SIZE;
        if (index == hashValue) {
            // 모든 버킷을 확인한 경우
            printf("[%2d] 탐색 실패\n", key);
            return; // 함수 종료
        }
    }
    printf("[%2d] 탐색 실패\n", key);
}

// Function to generate a random integer within a specified range
int generate_random_key(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to generate a single random character
char generate_random_char() {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    return charset[rand() % (sizeof(charset) - 1)];
}

int main() {
    init_map();

    // Insert some specific records
    add_record(3, "a");
    add_record(14, "b");
    add_record(25, "c");
    add_record(36, "d");
    add_record(58, "f");
    add_record(4, "abc");
    add_record(6, "cdd");

    // Generate and insert random records until the table is full
    while (1) {
        int key = generate_random_key(1, 100);  // Adjust the range of random keys as needed
        char value[2];  // Assuming you want a single random character
        value[0] = generate_random_char();
        value[1] = '\0';  // Null-terminate the string

        add_record(key, value);

        // Check if the table is full
        int cnt = 0;
        for (int j = 0; j < BUCKET_SIZE; j++)
            if (ht[j][SLOT_SIZE - 1].key != 0)
                cnt += 1;

        if (cnt == BUCKET_SIZE)
            break;  // Exit the loop if the table is full
    }

    print_map();
    search_record(3);

    return 0;
}
