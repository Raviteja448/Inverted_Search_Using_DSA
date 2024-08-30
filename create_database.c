
#include<stdio.h>
#include "header.h"
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

/*FUNCTION DEINATION FOR CREATE HASH TABLE*/
//printf("------------------------------------------------------------------------------\n");
int create_hash_table(hash_table *HT,int size)
{
    for (int i=0;i<size;i++)
    {
        HT[i].key=i;
        HT[i].link=NULL;
    }
    return SUCCESS;
}
//printf("-------------------------------------------------------------------------------\n");
int create_data_base(d_type_s1 **s1,hash_table *arr)
{
    d_type_s1 *temp=*s1;
    while (temp!=NULL)// IT RUNS NUMBER OF FILES TIMES
    {
        char scan_word[100];
        FILE *fptr=fopen(temp->file_name,"r");
        if (fptr==NULL) {
            printf("ERROR : Pointer pointing to null\n");
            return 1;
        }
        while( fscanf(fptr,"%s",scan_word)!= EOF )//READ STRING FROM THE FILE
        {       
            scan_word[strlen(scan_word)] = '\0';
            int index;
            //After Feteching word FIND THE INDEX IN HASH TABLE:
            if (isupper(scan_word[0]))//CONVERT INTO LOWER
                index=(scan_word[0]+32)-97;
            else if(isdigit(scan_word[0]))//IF IT IS DIGIT STORE IN 27 INDEX
                index=27;
            else if (ispunct(scan_word[0]))//SPECIAL CHARACTER MEANS STORE IN 26 INDEX
                index=26;
            else
                index=scan_word[0]-97;//OTHER FIND NORMAL WAY TO INDEX

            /*IF NODE IS EMPTY CREATE MEMORY FOR MAINNODE AND SUBNODE*/
            if(arr[index].link==NULL)
            {
                MAIN_NODE *s3=malloc(sizeof(MAIN_NODE));
                SUB_NODE *s2=malloc(sizeof(SUB_NODE));
                if (s2==NULL)
                {
                    printf("ERROR: SUBNODE MEMORY NOT ALLOCATED:\n");
                }
                s2->word_count = 1; //Storing Word count 1
                strcpy(s2->f_name,temp->file_name); //copyiing file name 
                s2->link = NULL; // assigning null with SUBNODE link Part
                if (s3==NULL)
                {
                    printf("ERROR: MAINNODE MEMORY NOT ALLOCATED:\n");
                }
            
            
                s3->s_link = s2;//STORING SUBNODE ADDRES IN MAINNODE SUBLINK
                s3->file_count = 1;//ASSIGNING FILE COUNT
                strcpy(s3->word, scan_word);//COPYING WORD INTO MAINNODE WORD (STRING)
                s3->m_link = NULL;//STORING NULL
                arr[index].link = s3;//STORING MAIN NODE ADDRES IN HASH_TABLE LINK
                continue;
            }  
            //IF HASH_TABLE LINK IS NOT NULL THEN 
            MAIN_NODE *temp_3=arr[index].link,*prev=NULL;
            int flag=0;

            /*WORDS ARE SAME THEN CHECKING SAME FILE OR NOT*/
            while(temp_3!=NULL)//checking words are same or Not IN ALL FILES 
            {
                if (strcmp(temp_3->word,scan_word)==0)//TWO WORDS ARE SAME 
                {
                    SUB_NODE *t=temp_3->s_link;//storing SUBNODE ADDRES IN *t
                    
                    while(t!=NULL)
                    {
                        if (strcmp(t->f_name,temp->file_name)==0)//CHECKING SAME FILES OR NOT
                        {
                             t->word_count++;//IF IT IS SAME FILES INCRASE WORD COUNT IN SUBNODE
                            flag=1;
                            break;
                        }
                        t=t->link;
                    }
                    if(flag==1){
                    break;//BREAK THE PRESENT LOOP
                    }
                    else//NOT SAME FILES STORE INTO ANOTHER SUBNODE AND INCREASE FILE COUNT 
                    {
                        SUB_NODE *new=malloc(sizeof(SUB_NODE));
                        strcpy(new->f_name,temp->file_name);//copying File name into SUBNODE 
                        new->word_count=1;//assigning count as 1 in SUBNODE
                        new->link=NULL;//NULL ASSIGNING IN SUBNODE
                        temp_3->file_count++;//INCREASE FILE COUNT IF IT IS ANOTHER FILE
                        //TRAVERSE UNTIL LAST SUBNODE
                        SUB_NODE *t =temp_3->s_link;
                        while(t->link!=NULL){
                            t=t->link;
                        }
                        t->link=new;//ASSIGNING NEW NODE ADDRES WITH LAST SUBNODE  LINK
                        flag=1;
                        break;
                    }
                }
                prev=temp_3;//STORING PREVIOUES NODE ADDRESS
                temp_3=temp_3->m_link;// MOVING MAIN NODE
            }

            if (flag==1){
            continue;//PRESENT ITERATION SKIP BEACUASE OF WORD IS ALREADY STORED 
            }

        /*THE WORDS ARE NOT SAME THEN CREATING MAIN NODE AND  ASSIGN THAT ADDRES PREVIOS MAIN NODE MAIN_LINK*/
            MAIN_NODE *s3=malloc(sizeof(MAIN_NODE));
            SUB_NODE *s2=malloc(sizeof(SUB_NODE));
            if (s2==NULL)
            {
                printf("ERROR: SUBNODE MEMORY NOT ALLOCATED:\n");
            }
            s2->word_count = 1; //Storing Word count 1
            strcpy(s2->f_name,temp->file_name); //copyiing file name 
            s2->link = NULL; // assigning null with SUBNODE link Part
            if (s3==NULL)
            {
                printf("ERROR: MAINNODE MEMORY NOT ALLOCATED:\n");
            }
            
            s3->s_link = s2;//STORING SUBNODE ADDRES IN MAINNODE SUBLINK
            s3->file_count = 1;//ASSIGNING FILE COUNT
            strcpy(s3->word, scan_word);//COPYING WORD INTO MAINNODE WORD (STRING)
            s3->m_link = NULL;//STORING NULL
            if (prev!=NULL)
            prev->m_link = s3;//STORING MAIN NODE ADDRES IN HASH_TABLE LINK(PREVIOSLY STORED NODE)
        }

        temp=temp->link;//MOVING TO ANOTHER NODE(NEXT FILE NAME) 

    }
    return SUCCESS;
//PRINTF("------------------------------------------------------------------------------------------\N");
}
