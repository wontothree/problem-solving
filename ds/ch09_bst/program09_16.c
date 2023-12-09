//
// Created by Kevin Liam on 2023/11/17.
//
// 단어장의 탐색 인터페이스 함수들
void search_word(char *word)
{
    TNode *n = search(root, word);
    if (n != NULL) {
        printf("    >> ");
        printf(" %12s : %-40s\n", n -> data.word, n -> data.meaning);
    }
    else printf("   >> 등록되지 않은 단어 : %s\n", word);
}

void search_meaning(char *m)
{
    TNode *n = search(root, m);
    if (n != NULL) {
        printf("    >> ");
        printf(" %12s : %-40s\n", n -> data.word, n -> data.meaning);
    }
    else printf("   >> 등록되지 않은 의미 : %s\n", m);
}