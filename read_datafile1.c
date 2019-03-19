#include"main.h"

FILE *  read_datafile(char *file_name)
{
    int i = 0;
    FILE * fptr = NULL;
    char word[20],ch;

    if(check_extension(file_name) != SUCCESS) return NULL;

    /*open the file */

    fptr = open_file(file_name,"r");
    if(fptr == NULL) return NULL;

    if(check_emptyness(fptr,file_name) != SUCCESS) return NULL;

    else
	return fptr;
}

