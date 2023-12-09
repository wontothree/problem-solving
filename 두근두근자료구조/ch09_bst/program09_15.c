//
// Created by Kevin Liam on 2023/11/17.
//
// 단어장의 삭제 인터페이스 함수
void delete_word(char* key)
{
    TNode* parent = NULL;
    TNode *n = root;
    int ret;

    while(n != NULL) {
        ret = strcmp(n -> data.word, kwy));
        if (ret == 0) break;
        parent = n;
        n = (ret < 0) ? n -> left : n -> right;
    }
    if (n == NULL) printf(" Error : key is not in the tree\n");
    else delete(parent, n);
}