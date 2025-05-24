#include <stdio.h>

int main(void) {
    int subject_num;
    scanf("%d", &subject_num);
    
    float score[1000], new_score[1000];
    for (int i = 0; i < 1000; i++) {
        score[i] = 0;
        new_score[i] = 0;
    }
    
    for (int i = 0; i < subject_num; i++) {
        scanf("%f ", &score[i]);
    }
    
    int max_score = score[0];
    for (int i = 0; i < subject_num; i++) {
        if (max_score < score[i]) {
            max_score = score[i];
        }
    }
    
    for (int i = 0; i < subject_num; i++) {
        new_score[i] = score[i] / max_score * 100;
    }
    
    float new_score_sum = 0;
    for (int i = 0; i < subject_num; i++) {
        new_score_sum += new_score[i];
    }
    
    printf("%f", new_score_sum / subject_num);
    
    return 0;
}