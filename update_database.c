#include<stdio.h>
#include "header.h"
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#if 1
int delete_node(d_type_s1 **head,char *ptr)
{
    d_type_s1 *temp=*head,*prev;
    if (temp!=NULL && strcmp(temp->file_name ,ptr)==0)//HAVING ONE NODE
    {
        *head =temp->link;//ASSIGNING NEXT NODES ADDRESS
        free(temp);//free the node
        return 0;
    }
    else
    {
        while(temp!=NULL)//MOVING UNTIL THAT NODE
        {
            prev=temp->link; //STORING NEXT NODE ADDRESS
            if (strcmp(temp->file_name, ptr)==0)
            {
                temp->link=prev->link;//STORING NEXT NODE ADDRES PRESENT NODE LINK
                free(prev);//FREE PRESENT NODE
                 return 0;
            }
            temp=temp->link;
            
        }
    }
}
#endif
int Update_database(hash_table *arr,d_type_s1 **s1)
{
    char str[50];
    printf("Enter the file Name: ");
    scanf("%s",str);
   
    char *ptr=strchr(str, '.');//taking extension
            if (ptr && strcmp(ptr,".txt")==0)//COMAPARING EXTENSION 
            {
                FILE *fptr = fopen(str, "r");
                if (fptr != NULL) 
                {
                    fseek(fptr, 0, SEEK_END); // moving to file end
                    long size = ftell(fptr); // taking file length
                    fclose(fptr); // close the file after getting the size
                    if (size == 0) {
                        printf("ERROR: File is Empty: %s\n", str);
                        return 0;
                    }
                    fptr = fopen(str, "r");
                    char scan_word[300];
                    int index;
                    while(fscanf(fptr,"%s",scan_word)!= EOF)
                    {
                       char *token = strtok(scan_word, "#;");//storing index value from first line
                        index=atoi(token);
                        MAIN_NODE *t=arr[index].link;//STORING MAIN NODE ADDRES INTO *T
                        if(arr[index].link!=NULL)//IF IT IS NOT  NULL 
                        {
                            while(t && t->m_link!=NULL)//MOVING LAST OF MAIN NODE
                            {
                                t=t->m_link;
                            }
                        }
                            MAIN_NODE *s3=malloc(sizeof(MAIN_NODE));
                            SUB_NODE *s2=malloc(sizeof(SUB_NODE));
                            if (s2==NULL){
                                    printf("ERROR: SUBNODE MEMORY NOT ALLOCATED:\n");
                                }
                            s2->link=NULL;
                            if (s3==NULL){
                                printf("ERROR: MAINNODE MEMORY NOT ALLOCATED:\n");
                            }
                            s3->m_link=NULL;
                            s3->s_link=NULL;
                            strcpy(s3->word,strtok(NULL,"#;"));//STORING WORD IN MAIN NODE
                            s3->file_count=atoi(strtok(NULL,"#;"));//STORING FILE COUNT IN MaIN NODE
                            strcpy(s2->f_name,(strtok(NULL,"#;")));//STORING FILE NAME IN SUNBONE 
                            s2->word_count=atoi(strtok(NULL,"#;"));//STORING WORD COUNT IN SUBNODE
                            delete_node(&(*s1),s2->f_name);//REMOVE THAT FILE NAME IN CREATE LIST
                            s3->s_link=s2;//STORING SUBNODE ADDRES IN MAIN NOD SUB_LINK;
                            SUB_NODE *temp2=s2;//STORING SUBNODE ADDRES IN TEMP2
                            for (int i=0;i<(s3->file_count-1) && temp2!= NULL;i++)//ITERATING FILE COUNT -1 TIME BECAUSE OF ALREADY ONE SUBNODE CREATED WITH MAIN NODE
                            {
                                
                                SUB_NODE *s2=malloc(sizeof(SUB_NODE));
                                if (s2==NULL)
                                {
                                    printf("ERROR: SUBNODE MEMORY NOT ALLOCATED:\n");
                                }
                                s2->link=NULL;
                                strcpy(s2->f_name,strtok(NULL,"#;"));//STORING FILE NAME IN SUNBONE 
                                s2->word_count=atoi(strtok(NULL,"#;"));//STORING WORD COUNT IN SUBNODE
                                delete_node(&(*s1),s2->f_name);//REMOVE THAT FILE NAME IN CREATE LIST
                                temp2->link=s2; // SUBNODE LINK WITH NEW SUBNODE ADDRESS
                                temp2=s2;//STORING NEW SUBNODE ADDRESS IN TEMP
                             
                            }

                            if (arr[index].link==NULL)//FIRST MAIN NODE
                            { 
                                arr[index].link=s3;//ASSSIGN THE NEW MAIN ADDRES TO LAST MAIN NODE LINK
                            }
                            else//AFTER TRAVERSE LINKING WITH MAINNODE MAIN_LINK WITH NEW MAIN NODE ADDRESS
                            {
                                t->m_link=s3;//ASSSIGN THE NEW MAIN ADDRES TO LAST MAIN NODE LINK
                            }   
                    }
                }
                else
                     printf("ERROR: File Does Not Exist: %s\n", str);
        } 
         else 
            printf("ERROR: File \"%s\" Extension Should Be \".txt\"\n", str);

    return 1;
}