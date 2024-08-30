#include<stdio.h>
#include "header.h"
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
/*DISPLAY FUNCTION DEFINATION*/
int display_database(hash_table *arr) {
    printf("---------------------------------------------------------------------------------------\n");
    printf(" INDEX:\t  FILE_COUNT:\t  WORD:\t\t  FILE_NAME:\t WORD_COUNT:\n");
    printf("---------------------------------------------------------------------------------------\n");
    for (int i = 0; i < 28; i++) {
        if (arr[i].link != NULL) {
            MAIN_NODE *main = arr[i].link;
            while (main != NULL) {
                printf("%d\t %-15d %-12s\t", i, main->file_count, main->word);
                SUB_NODE *sub = main->s_link;
                while (sub != NULL) {
                    printf("%-15s\t %-10d", sub->f_name, sub->word_count);
                    sub = sub->link;
                }
                main = main->m_link;
                printf("\n");
            }
        }
    }
    printf("---------------------------------------------------------------------------------------\n");
    return SUCCESS;
}
/*SAVE_DATABASE FUNCTION DEFINATION*/
#if 1
int Save_database(hash_table *arr) {
   char str[50];
   printf("Enter the file name: ");
   scanf("%s",str);
char *ptr = strchr(str, '.');
if (ptr && strcmp(ptr, ".txt") == 0)
{
   FILE *fptr=fopen(str,"w+");
    for (int i = 0; i < 28; i++)
     {
        if (arr[i].link != NULL) 
        {
            MAIN_NODE *main = arr[i].link;
            while (main != NULL) {
                fprintf(fptr,"#%d;%s;%d;", i,main->word,main->file_count);
                SUB_NODE *sub = main->s_link;
                while (sub != NULL) {
                    fprintf(fptr,"%s;%d;", sub->f_name, sub->word_count);
                    sub = sub->link;
                }
                main = main->m_link;
                fprintf(fptr,"#%s","\n");
            }
        }
    }
} 
else 
    printf("ERROR: File \"%s\" Extension Should Be \".txt\"\n", str);
    return SUCCESS;
}
#endif


