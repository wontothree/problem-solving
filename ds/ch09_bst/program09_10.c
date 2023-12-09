//
// Created by Kevin Liam on 2023/11/17.
//
// 단어장 프로그램의 main 함수
void main()
{
    char command, word[80], meaning[200];

    do{
        printf("[사용법] i-추가 d-삭제 w-단어검색 m-의미검색 p-출력 q-종료 => ");
        command = getche();
        printf("\n");

        switch(command)
        {
            case 'i' :
                printf("    > 삽입 단어 : "); gets(word);
                printf("    > 단어 의미 : "); gets(meaning);
                insert_word(word, meaning);
                break;
            case 'd' :
                printf("    > 삭제 단어 : "); gets(word);
                delete_word(word);
                break
            case 'p' :
                printf_dic();
                break;
            case : 'w' :
                printf("    > 단어 검색 : "); gets(word);
                search_word(word);
                break;
            case : 'm' :
                printf("    > 검색 의미 : "); gets(word);
                search_meaning(word);
                break;
        }
    } while(command = 'q');
};