//
// Created by Kevin Liam on 2023/10/25.
//
// 주어진 이진트리에서 노드가 가지고 있는 값이 주어진 value보다 작으면 노드의 값을 출력하는 프로그램을 작성하라.
//값을 입력하시오: 30
//30보다 작은 노드: 10
//30보다 작은 노드: 9
//30보다 작은 노드: 29

#include <stdio.h>
#include <stdlib.h>

typedef int TElement;
typedef struct BinTrNode {
    TElement data;
    struct BinTrNode* left;
    struct BinTrNode* right;
} TNode;

TNode* root;
void init_tree() {root = NULL;}
int is_empty_tree() {return root == NULL;}
TNode* create_node(TElement val, TNode* l, TNode* r) {
    TNode *n = (TNode *) malloc(sizeof(TNode));
    n->data = val;
    n->left = l;
    n->right = r;
    return n;
}
TNode* get_root() {return root;}

void is_small(TNode* r, TElement value) {
    if (r == NULL) return;
    if (r -> data < value)
        printf("%d보다 작은 노드: %d", value, r -> data);
}

int main(void)
{
    TNode *a, *b, *c, *d, *e, *f, *g, *h, *i, *j, *k, *l, *m, *n, *o, *p;
    h = create_node(8, NULL, NULL);
    i = create_node(9, NULL, NULL);
    j = create_node(10, NULL, NULL);
    k = create_node(11, NULL, NULL);
    l = create_node(12, NULL, NULL);
    m = create_node(13, NULL, NULL);
    n = create_node(14, NULL, NULL);
    o = create_node(15, NULL, NULL);
    p = create_node(16, NULL, NULL);
    d = create_node(4, f, g);
    e = create_node(5, h, i);
    f = create_node(6, j, k);
    g = create_node(7, l, m);
    b = create_node(2, d, e);
    c = create_node(3, f, g);
    a = create_node(1, b, c);

    return 0;
}