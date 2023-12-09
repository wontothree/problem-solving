//
// Created by Kevin Liam on 2023/11/17.
//
// 단어장 프로그램
#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
//#include <curses.h>
#include <string.h>
#define MAX_WORD_SIZE 40
#define MAX_MEANING_SIZE 200
typedef struct DicRecord {
    char word[MAX_WORD_SIZE];
    char meaning[MAX_MEANING_SIZE];
} Record;

typedef Record TElement;
typedef struct BinTrNode {
    TElement data;
    struct BinTrNode *left;
    struct BinTrNode *right;
} TNode;
TNode* root = NULL;

int is_empty_tree() {return root == NULL;}
TNode* create_tree(TElement val, TNode* l, TNode* r)
{
    TNode* n = (TNode*) malloc(sizeof(TNode));
    n -> data = val;
    n -> left = l;
    n -> right = r;
    return n;
}

TNode* search(TNode *n, char* key)
{
    if (n == NULL) return NULL;
    else if (strcmp(n -> data.word, key) == 0) return n;
    else if (strcmp(n -> data.meaning, key) < 0) return search(n -> left, key);
    else return search(n -> right, key);
}

void insert(TNode* r, TNode* n)
{
    int ret = strcmp(r -> data.word, n-> data.word);

    if(ret == 0) return;
    if( ret < 0) {
        if (r -> left == NULL) r -> left = n;
        else insert(r -> left, n);
    }
    else {
        if (r -> right == NULL) r -> right = n;
        else insert(r -> right, n);
    }
}

void delete (TNode* parent, TNode* n)
{
    TNode *child, *succ, *succp;

    // case 1
    if ((n -> left == NULL && n -> right == NULL)) {
        if (parent == NULL) root = NULL;
        else {
            if (parent -> left == n)
                parent -> left = NULL;
            else parent -> right = NULL;
        }
    }

        // case 2
    else if (n -> left == NULL || n -> right == NULL) {
        child = (n -> left != NULL) ? n -> left : n -> right;
        if (n == root) root = child;
        else {
            if (parent -> left == n)
                parent -> left = child;
            else parent -> right = child;
        }
    }

        // case 3
    else {
        succp = n;
        succ = n -> right;
        while (succ -> left != NULL) {
            succp = succ;
            succ = succ -> left;
        }
        if (succp -> left == succ) succp -> left = succ -> right;
        else succp -> right = succ -> right;

        n -> data = succ -> data;
        n = succ;
    }
    free(n);
}

static TNode* search1(TNode *n, char* meaning)
{
    TNode* m;
    if (n == NULL) return NULL;
    if (strcmp(n -> data.meaning, meaning) == 0) return n;

    m = search1(n -> left, meaning);
    if (m != NULL) return m;
    else return search1(n -> right, meaning);
}

void inorder(TNode *n)
{
    if (n != NULL) {
        inorder(n -> left);
        printf(" %12s : %-40s\n", n -> data.word, n -> data.meaning);
        inorder(n -> right);
    }
}

TNode* insert_word(char* key, char* val)
{
    TNode *n;
    Record r;
    strcpy(r.word, key);
    strcpy(r.meaning, val);
    n = create_tree(r, NULL, NULL);

    if(is_empty_tree()) root = n;
    else insert(root, n);
    return root;
}

void delete_word(char* key)
{
    TNode* parent = NULL;
    TNode *n = root;
    int ret;

    while(n != NULL) {
        ret = strcmp(n -> data.word, key);
        if (ret == 0) break;
        parent = n;
        n = (ret < 0) ? n -> left : n -> right;
    }
    if (n == NULL) printf(" Error : key is not in the tree\n");
    else delete(parent, n);
}

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

void print_dic()
{
    printf("    >> 나의 단어장:\n");
    if (root != NULL) inorder(root);
}

int main()
{
    char command, word[80], meaning[200];

    do{
        printf("[사용법] i-추가 d-삭제 w-단어검색 m-의미검색 p-출력 q-종료 => ");
        command = getch();
        printf("\n");

        switch(command)
        {
            case 'i' :
                printf("    > 삽입 단어 : "); fgets(word, sizeof(word), stdin);
                printf("    > 단어 의미 : "); fgets(word, sizeof(meaning), stdin);
                insert_word(word, meaning);
                break;
            case 'd' :
                printf("    > 삭제 단어 : "); fgets(word, sizeof(word), stdin);
                delete_word(word);
                break;
            case 'p' :
                print_dic();
                break;
            case 'w' :
                printf("    > 단어 검색 : "); fgets(word, sizeof(word), stdin);
                search_word(word);
                break;
            case 'm' :
                printf("    > 검색 의미 : "); fgets(word, sizeof(word), stdin);
                search_meaning(word);
                break;
        }
    } while(command != 'q');
    return 0;
};