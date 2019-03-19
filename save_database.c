#include"main.h"

int save_database(char * file_name, data_base db_ary[])
{
    FILE * fp ; //file pointer
    int i;
    file_table *tmp;
    Slist *tmp_1;
    printf("Creating the %s.csv file to store the data base\n",file_name);

    //to save filename .csv extension
    file_name = strcat(file_name , ".csv");   


    //open_file function open the file in specified mode along with error checking
    if(  ( fp = open_file(file_name, "w+" )) == NULL )  return FAILURE;


    /*start writing the data base content to file*/
    fprintf(fp , "FILE COUNT,WORD,WORD COUNT,FILE NAME\n");

    for( i = 0; i < 26; i++ )
    {
	if(db_ary[i].word[0] != '\0')
	{ 
	    fprintf(fp, "%d, %s ,",  db_ary[i].file_count, db_ary[i].word);

	    //get the address of the file_table to temp
	    tmp = 	 db_ary[i].tab_link;

	    while(tmp != NULL)
	    {
		fprintf(fp, "%d, %s,",tmp->word_count, tmp->file_name);


		//go to next node
		tmp = tmp->tab_link;


	    } 

	    fputc('\n',fp);
	    tmp_1 = db_ary[i].link;
	    while(tmp_1 != NULL)
	    {
		fprintf(fp , "%d,%s,",tmp_1->file_count, tmp_1->word);

		tmp = tmp_1->file_table;
		while(tmp != NULL)
		{
		    fprintf(fp , "%d,%s,", tmp->word_count, tmp->file_name);
		    tmp = tmp->tab_link;
		}

		fputc('\n',fp);
		tmp_1 = tmp_1->link;
	    }

	}

    }

    return SUCCESS;
}





