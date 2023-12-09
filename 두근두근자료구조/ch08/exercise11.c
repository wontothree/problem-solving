//
// Created by Kevin Liam on 2023/10/25.
//
// 11. 다음과 같은 함수가 아래에 표시된 이진트리의 루트 노드에 대해 호출된다고 하자. 함수가 반환하는 값은 무엇인가?
// [변형 문제] + 주어진 트리를 구현하라.

#include <stdio.h>
#include <stdlib.h>

typedef int TElement;

typedef struct BinTrNode {
    TElement data;
    struct BinTrNode* left;
    struct BinTrNode* right
} TNode;

TNode* root;

void init_tree() {root = NULL;}
int is_empty_tree() {return root == NULL;}
TNode* get_root() {return root;}
TNode* create_tree(TElement val, TNode* l, TNode* r) {
    TNode* n = (TNode*)malloc(sizeof(TNode));
    n -> left = l;
    n -> right = r;
    n -> data = val;
    return n;
}

int mystery(TNode* p)
{
    if (p == NULL)
        return 0;
    else if (p -> left == NULL && p -> right == NULL)
        return p -> data;
    else return mystery(p -> left) > mystery(p -> right) ? mystery(p -> left) : mystery(p -> right);
}

int find_max(TNode* p) {
    if (p == NULL) {
        return 0; // 가장 작은 정수값을 반환 (INT_MIN은 limits.h에서 정의된 값)
    } else {
        int max_left = find_max(p->left);
        int max_right = find_max(p->right);
        int max_child = max_left > max_right ? max_left : max_right;
        return p->data > max_child ? p->data : max_child;
    }
}

void main(void)
{
    TNode *a, *b, *c, *d, *e, *f, *g;
    g = create_tree(6, NULL, NULL);
    f = create_tree(8, NULL, NULL);
    e = create_tree(2, NULL, NULL);
    d = create_tree(4, NULL, NULL);
    c = create_tree(1, f, g);
    b = create_tree(10, d, e);
    a = create_tree(3, b, c);

    printf("반환값: %d\n", mystery(a));
    printf("반환값: %d\n", find_max(a));
}



