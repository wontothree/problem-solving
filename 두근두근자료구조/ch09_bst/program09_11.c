//
// Created by Kevin Liam on 2023/11/17.
//
// 단어장을 위한 탐색 연산
TNode* search(TNode *n, char* key)
{
    if (n == NULL) return NULL;
    else if (strcmp(n -> data, key) == 0) return n;
    else if (strcmp(n -> data, key) < 0) return search(n -> left, key);
    else return search(n -> right, key);
}