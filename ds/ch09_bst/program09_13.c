//
// Created by Kevin Liam on 2023/11/17.
//
// 단어장을 위함 탐색 연산
static TNode* search1(TNode *n, char* meaning)
{
    TNode* m;
    if (n == NULL) return NULL;
    if (strcmp(n -> data.meaning, meaning) == 0) return n;

    m = search1(n -> left, meaning);
    if (m != NULL) return m;
    else return earch1(n -> right, meaning);
}