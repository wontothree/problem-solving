//
// Created by Kevin Liam on 2023/11/17.
//
// 단어장을 위한 삽입 연산
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
