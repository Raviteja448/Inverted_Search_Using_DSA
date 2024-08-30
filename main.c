#include<stdio.h>
#include<string.h>
#include"header.h"
#define MAX_SIZE 28

int main(int argc,char **argv)
{

	if (argc==1)
	{
		printf("ERROR: Pass Command line Arguments:\n");
		printf("Ex: ./a.out file.txt\n");
		return 1;
	}
	
	d_type_s1 *s1=NULL;
	if(read_and_validate(argv,&s1))
		printf("INFO : Read And Validation DONE: \n");
	else
	printf("INFO : Read And Validation NOT-DONE: \n");
	d_type_s1 *temp=s1; 
	int i=1;
	while(temp!=NULL)
	{
		printf("file[%d] = %s \n",i,temp->file_name);
		temp=temp->link;
		i++;
	}
	
	hash_table arr[MAX_SIZE];
	if(create_hash_table(arr,MAX_SIZE))
		printf("INFO : HASH_TABLE CREATION DONE: \n");
	else
		printf("INFO : HASH_TABLE CREATION NOT-DONE: \n");
	int option,flag=0;
	while (1)
	{
		printf("The Contents:\n 1.Create Database\n 2.Display Databse\n 3.Search Database\n 4.Save Database\n 5.Update Database\n 6.Exit\nEnter your Choice: ");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				if(create_data_base(&s1,arr))
				{
					printf("INFO : CREATE DATA_BASE DONE: \n");
					flag=1;
				}
				else
					printf("INFO : CREATE DATA_BASE NOT-DONE: \n");
				break;
			case 2:
				if (flag==1)
				{
					if(display_database(arr))
						printf("INFO : DISPLAY_FUNCTION DONE: \n");
					else
						printf("INFO : DISPLAY_FUNCTION NOT-DONE: \n");
				}
				else
				printf("DATA_BASE IS NOT CREATED\n");
			break;
			case 3:
				if (flag==1)
				{
					if(Search_database(arr))
						printf("INFO : SEARCH_FUNCTION DONE: \n");
					else
						printf("INFO : SEARCH_FUNCTION NOT-DONE: \n");
				}
				else
				printf("DATA_BASE IS NOT CREATED \n");
			break;
			case 4:
				if (flag==1)
				{
					if(Save_database(arr))
						printf("INFO : SAVE_FUNCTION DONE:\n");
					else
						printf("INFO : SAVE_FUNCTION NOT-DONE:\n");
				}
				else
				printf("DATA_BASE IS NOT CREATED \n");
			break;
			case 5:
				if (flag==0)
				{
					if(Update_database(arr,&s1))
						printf("INFO : UPDATE_FUNCTION DONE: \n");
					else
						printf("INFO : UPDATE_FUNCTION NOT-DONE: \n");
					flag=1;
				}
				else 
					printf("HASH_TABLE IS HAVING INFORMATIOM \n");
			break;
			case 6:
				printf("Your Exited\n");
				return 0;
			break;	
			default :
				printf("INVALID_INPUT\n");
			break;
		}
		
	}
}

