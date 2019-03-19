#ifndef MAIN_H
#define MAIN_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define FAILURE -1
#define EMPTY -3
#define DATA_NOT_FOUND -2
#define SUCCESS 0

#define CREATE_DATABASE 1
#define SEARCH 2
#define DISPLAY_DATABASE 3
#define SAVE_DATABASE 4
#define UPDATE_DATABASE 5
#define EXIT 6

#define SIZE 26
//int no_file;   //global variable
typedef char data_t;
//FILE * fptr = NULL;
typedef struct node
{
	int file_count;
	struct node *link;
	char word[10];
	struct fi_tab *file_table;
}Slist;

/*struct defination of data_base*/
typedef struct hash
{
    int index;
    int file_count;
    char word[10];
    struct node * link;
    struct fi_tab * tab_link;
}data_base;

/*struct defination for same words*/
typedef struct fi_tab
{
	int word_count;
	char * file_name;
	struct fi_tab *tab_link;
}file_table;


FILE * open_file(const char * file_name, const char * mode);
char ** input_from_user(int no_file);
FILE * read_datafile(char * file_name);
int check_extension(const char * file_name);
int check_emptyness(FILE * fptr,char *file_name);
void default_database(data_base data_base_array[]);
int hash_indx(char * token);

char * word_extractor(FILE *fptr);
file_table * create_sll(void);
Slist * create_same_frst_letter_node(void);
int str_cmp(const char *  left, const char *  right);
int save_database(char * file_name, data_base db_ary[]);

int  create_data_base(data_base db_ary[], char **flist, int no_file);
int display_data_base(data_base db_ary[]);
int search_data_base(data_base db_ary[], char * s_data);

#endif

