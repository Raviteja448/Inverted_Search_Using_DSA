#include<stdio.h>
#include "header.h"
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int Search_database(hash_table *arr)
{
    char scan_word[50];
    printf("Enter The Word To Search : ");
    scanf("%s",scan_word);
    int index;
    if (isupper(scan_word[0]))//CONVERT INTO LOWER
        index=(scan_word[0]+32)-97;
    else if(isdigit(scan_word[0]))//IF IT IS DIGIT STORE IN 27 INDEX
        index=27;
    else if (ispunct(scan_word[0]))//SPECIAL CHARACTER MEANS STORE IN 26 INDEX
        index=26;
    else
        index=scan_word[0]-97;
    MAIN_NODE *main=arr[index].link;
     while (main != NULL) 
     {
        if (strcmp(main->word,scan_word)==0){
             printf("---------------------------------------------------------------------------------------\n");
            printf(" INDEX:\t  FILE_COUNT:\t  WORD:\t\t  FILE_NAME:\t WORD_COUNT:\n");
            printf("---------------------------------------------------------------------------------------\n");
            printf("[%d]\t %-15d %-12s\t", index, main->file_count, main->word);
            SUB_NODE *sub = main->s_link;
            while (sub != NULL) {
                printf("%-15s\t %-10d", sub->f_name, sub->word_count);
                sub = sub->link;
            }
            printf("\n---------------------------------------------------------------------------------------\n");
            return SUCCESS;
        }
        main = main->m_link;
     }
     printf("---------------------------------------------------------------------------------------\n");
     printf("DATA_NOT FOUND:\n");
     printf("---------------------------------------------------------------------------------------\n");
     return SUCCESS;

}