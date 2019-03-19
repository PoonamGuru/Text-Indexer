#include "main.h"


FILE * open_file(const char * file_name,const char * mode)
{
    FILE * fptr1 = fopen(file_name, mode);

    if(fptr1 == NULL)
    {
	perror("fopen");
	printf("ERROR : %s is not openned successfully\n",file_name);
	return NULL;
    }

    else
    {
	printf("INFO : %s is opened successfully\n", file_name);
	return fptr1;
    }

}



int check_extension(const char * file_name)
{
    int i = 0;
    /*checking the file extension*/
    while((file_name[i] != '.') && (file_name[i] != '\0'))
	i++;
    if(strcmp((file_name+i),".txt") != 0)
    {
	printf("ERROR : enter the file name with extension .txt\n");
	return FAILURE;
    }
    else
    {
	printf("INFO : correct FILE EXTENSION\n");
	return SUCCESS;
    }

}


int check_emptyness(FILE *fptr, char * file_name)
{ 
    rewind(fptr);

    /* check file is empty or not*/
    fseek(fptr,0L,2);
    if(ftell(fptr)  != 0)
    {
	printf("INFO : \"%s\" is not empty\n",file_name);
	rewind(fptr);
	return SUCCESS;
    }
    else
    {
	printf("ERROR : \"%s\" is Empty\n",file_name);

	rewind(fptr);
	return FAILURE;
    }

}

/*name : default_database
 *input : hash table
 *output : void
 *discription : this function create a default hash table
 */



void default_database(data_base data_base_array[])
{
    int i;

    for(i = 0; i< SIZE; i++)
    {
	data_base_array[i].index = i;
	data_base_array[i].file_count = 0;
memset(	data_base_array[i].word,'\0',10);
	data_base_array[i].link = NULL;
	data_base_array[i].tab_link = NULL;
    }

}



file_table * create_sll(void)
{
    file_table * new = malloc(sizeof(file_table));
    if(new != NULL)
    {
	new->word_count = 0;
	new->file_name = NULL;
	new->tab_link = NULL;

	return new;
    }

    return NULL;
}


int hash_indx(char * token)
{
    int indx;
    /*check whether it is upper or lower word to find the index*/
    if(token[0] >= 'a' && token[0] <= 'z' )
    {
	//printf("%c",token[0]);
	indx = (token[0] - 'a') % SIZE;
    }

    else if (token[0] >= 'A' && token[0] <= 'Z' )
    {
	//printf("%c\n",token[0]);
	indx = (token[0] - 'A') % SIZE;
    }
    //                      printf("%d\n",indx);

    return indx;

}


/*Name : same_first_letter
 */

Slist * create_same_frst_letter_node(void)
{
    Slist * new = malloc(sizeof(Slist));
    if(new == NULL)
	return NULL;

    new->file_count = 0;
    new->link = NULL;
    memset(new->word,'\0',10);
    new->file_table = NULL;
    return new;
}


/*name :str_cmp*/

int str_cmp(const char *  left, const char *  right)
{
    int i = 0, j = 0;

    while(left[i] != '\0' && right[j] != '\0')
    {
	if(left[i] == right[j] || left[i] - right[j]  == 32 || left[i] - right[j] == -32)
	{
	    i++;
	    j++;
	}


	else
	    return (left[i] - right[j]);
    }

    if(left[i] == '\0' && right[j] == '\0')
    {
	//printf("same :%d,%d\n",i,j);
	//printf("left = %d, right = %d\n",left[i],right[j]);
	return 0;
    }

    else
    {

	//printf("not same : %d,%d\n",i,j);
	return -1;
    }

}




