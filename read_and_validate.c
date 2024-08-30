
#include<stdio.h>
#include "header.h"
#include<string.h>
#include<stdlib.h>

int read_and_validate(char **argv, d_type_s1 **s1) {
    char str[50];
    int i = 1;

    while (argv[i] != NULL)
    {
        d_type_s1 *temp = *s1;
        strcpy(str, argv[i++]);
        char *ptr = strchr(str, '.');
        if (ptr && strcmp(ptr, ".txt") == 0)
        {
                FILE *fptr = fopen(str, "r");
                if (fptr != NULL)
            {
                fseek(fptr, 0, SEEK_END); // moving to file end
                long size = ftell(fptr); // taking file length
                fclose(fptr); // close the file after getting the size
                if (size == 0) {
                    printf("ERROR: File is Empty: %s\n", str);
                    continue;
                }
                int is_duplicate = 0;
                while (temp != NULL) {
                    if (strcmp(str, temp->file_name) == 0) {
                        printf("ERROR: Duplicate file \"%s\"\n", str);
                        is_duplicate = 1;
                        break;
                    }
                    temp = temp->link;
                }
                if (is_duplicate) {
                    continue;
                }
                temp = *s1;
                d_type_s1 *new = malloc(sizeof(d_type_s1));
                if (new == NULL) {
                    printf("ERROR: Memory Not Allocated\n");
                    continue;
                }

                strcpy(new->file_name, str); // assigning file name to structure variable
                new->link = NULL; // link part with null

                if (temp == NULL)  // having 0 nodes
                    *s1 = new;
                else 
                {
                    while (temp->link != NULL)//HAVING MULTIPLE NODES
                        temp = temp->link;
                    temp->link = new; // ASSIGNING NEW NODE ADRRES TO LAST NODE OF LIST
                }
            }
             else 
                printf("ERROR: File Does Not Exist: %s\n", str);
        } 
         else 
            printf("ERROR: File \"%s\" Extension Should Be \".txt\"\n", str);
    }
    return SUCCESS;
}
