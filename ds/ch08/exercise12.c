//
// Created by Kevin Liam on 2023/10/25.
//
// 12. 주어진 이진트리에서 노드가 자기고 있는 값의 합을 계산하는 프로그램을 작성해보자.
// 노드의 합은 129입니다.

#include <stdio.h>
#include <stdlib.h>

typedef int TElement;
typedef struct BinTrNode {
    TElement data; // 노드에 저장할 데이터
    struct BinTrNode* left; // 왼쪽 자식 노드의 포인터
    struct BinTrNode* right; // 오른쪽 자식 노드의 포인터
} TNode;

TNode* root; // root node의 포인터

void init_tree() {root = NULL;}
int is_empty_tree() {return root == NULL;}
TNode* get_root() {return root;}

TNode* create_tree(TElement val, TNode* l, TNode* r)
{
    TNode* n = (TNode*)malloc(sizeof(TNode));
    n -> data = val;
    n -> left = l;
    n -> right = r;
    return n;
}

int sum_node(TNode *n)
{
    if(n == NULL) return 0;
    int left_sum = sum_node(n -> left);
    int right_sum = sum_node(n -> right);
    return n -> data + left_sum + right_sum;
}

int main()
{
    TNode *a, *b, *c, *d, *e, *f, *g, *h, *i, *j;

    init_tree();
    g = create_tree(7, NULL, NULL);
    h = create_tree(8, NULL, NULL);
    i = create_tree(9, NULL, NULL);
    j = create_tree(10, NULL, NULL);
    f = create_tree(6, NULL, NULL);
    d = create_tree(4, g, h);
    e = create_tree(5, i, j);
    b = create_tree(2, d, e);
    c = create_tree(3, NULL, f);
    a = create_tree(1, b, c);
    printf("모든 노드의 합 = %d\n", sum_node(a));
    return 0;
}

