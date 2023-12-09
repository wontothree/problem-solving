//
// Created by Kevin Liam on 2023/11/17.
//
// 단어장의 삽입 인터페이스 함수
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