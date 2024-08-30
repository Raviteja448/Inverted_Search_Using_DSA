#include<stdio.h>
#define FILE_SIZE 50
#define WORD_SIZE 50
#define SUCCESS 1
#define FAILURE 0

//structure1 storing FILES NAMES
typedef struct node1
{
	char file_name[FILE_SIZE];
	struct node1 *link;

}d_type_s1;
//STRUCTURE  FOR SUBNODE
typedef struct sub
{
	int word_count;
	char f_name[FILE_SIZE];
	struct sub *link;
	
}SUB_NODE;
//STRUCTURE FOR MAIN NODE
typedef struct main
{
	int file_count;
	char word[FILE_SIZE];
	struct sub *s_link;
	struct main *m_link;
	
}MAIN_NODE;
//STRUCTURE FOR HASH TABLE
typedef struct hash
{
	int key;//TO STORES THE INDEX VALUE OF HASH TABLE
	struct main *link;//TO STORES THE MAIN NODE ADDRESS
}hash_table;

int read_and_validate(char **argv,d_type_s1 **s1);
int create_hash_table(hash_table *HT,int size);
int create_data_base(d_type_s1 **s1,hash_table *arr);
int display_database(hash_table *arr);
int Search_database(hash_table *arr);
int Save_database(hash_table *arr);
int Update_database(hash_table *arr,d_type_s1 **s1);
int delete_node(d_type_s1 **head,char *ptr);