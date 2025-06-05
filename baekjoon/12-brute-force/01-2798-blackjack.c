#include <stdio.h>

int main() {
    int card_num, pick_num;
    scanf("%d %d", &card_num, &pick_num);
    
    // initialize
    int cards[100];
    for (int i = 0; i < 100; i++) {
        cards[i] = 0;
    }
    
    for (int i = 0; i < card_num; i++) {
        scanf("%d", &cards[i]);
    }
    
    int result = 0;
    for (int i = 0; i < card_num; i++) {
        for (int j = i + 1; j < card_num; j++) {
            for (int k = j + 1; k < card_num; k++) {
                int sum =  cards[i] + cards[j] + cards[k];
                if (sum <= pick_num && sum > result) {
                    result = sum;
                }
            }
        }
    }
    
    printf("%d\n", result);
    
    return 0;
}