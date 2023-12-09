//
// Created by Kevin Liam on 2023/11/17.
//
// 단어장의 출력 인퍼페이스 함수들

void inorder(TNode *n)
{
    if (n != NULL) {
        inorder(n -> left);
        printf(" %12s : %-40s\n", n -> data.word, n -> data.meaning);
        inorder(n -> right);
    }
}

void print_dic()
{
    printf("    >> 나의 단어장:\n");
    if (root != NULL) inorder(root);
}