#include"main.h"


int create_data_base(data_base db_ary[],char **flist, int no_file)
{
    file_table *node = NULL;
    file_table * tmp = NULL;
    Slist * tmp_1 = NULL;
    Slist * tmp_4;
    int i = 0, j = 0,indx;
    char ch;
    char * word = malloc(100*sizeof(char));
    char *token;
    FILE * fptr;  



    for(i = 0;i < no_file; i++)
    {
	/*open the file in read mode and return fptr*/
	if((fptr = read_datafile(flist[i])) == NULL)  return FAILURE;


	/*read file content store it in word*/
	while((word[j] = fgetc(fptr)) != EOF)
	    j++;
	word[j] = '\0';
	//	printf("extracted word :%s\n",word);

	/*extract indivisual words*/
	token = strtok(word," ");

	while(token != NULL)
	{

	    indx = hash_indx(token); //find the index


	    if(indx >=0 && indx <=25)
	    { 
		//				printf("indx %d\n",indx);	       
	/*---------------------------------------------------- case 1 storing a word if db_ary[indx].word is NULL---------------------------------------*/
		if(db_ary[indx].word[0] == '\0')
		{

		    strcpy(db_ary[indx].word,token);   //store the word
		    db_ary[indx].file_count += 1; //increment the file count
		    if(db_ary[indx].tab_link == NULL) // create a file table
		    {
			if((db_ary[indx].tab_link = create_sll()) != NULL) 
			{
			    db_ary[indx].tab_link->word_count++;

			    db_ary[indx].tab_link->file_name = flist[i];
			}
		    }
		}



		/*-------------------------------------------------case 2 : same first letter but diffrent word from same file-----------------------------*/
		else if(((strcmp(db_ary[indx].word,token)) != 0) &&  toupper(db_ary[indx].word[0]) ==toupper( token[0])  )
		{

		    //list is empty
		    if(db_ary[indx].link == NULL)
		    {
			db_ary[indx].link = create_same_frst_letter_node();
			strcpy(db_ary[indx].link->word,token); 
			db_ary[indx].link->file_count++;

			db_ary[indx].link->file_table = create_sll();
			db_ary[indx].link->file_table->word_count++; 	
			db_ary[indx].link->file_table->file_name = flist[i];

		    }

		    else
		    {
			tmp_1 = db_ary[indx].link;

			while(tmp_1 != NULL)
			{
			    if( strcmp(tmp_1->word,token) == 0 ) 
			    {
				if ( strcmp (tmp_1->file_table->file_name, flist[i]) == 0)
				{
				    tmp_1->file_table->word_count++;
				    break;
				}


				else
				{
				    tmp = tmp_1->file_table;
				    while(tmp->tab_link != NULL)
				    {
					tmp = tmp->tab_link;
					if( strcmp(tmp->file_name , flist[i] ) == 0)
					    tmp->word_count++;

				    }


				    if(tmp->tab_link == NULL)
				    {
					if(strcmp(tmp->file_name ,flist[i]) != 0)
					{
					    tmp_1->file_count++;
			//		    printf("not hash%d\t%s\n",tmp_1->file_count, token);
					    if( (tmp->tab_link = create_sll() ) != NULL)
					    {
						tmp->tab_link->word_count++;
						tmp->tab_link->file_name = flist[i];
					    }
					}
				    }
				}
				break;
			    }
			    tmp_4 = tmp_1;
			    tmp_1 = tmp_1->link;
			}

			if(tmp_1 == NULL)
			{

			    //create a node and insert at last
			    if((tmp_1 = create_same_frst_letter_node()) == NULL)
				return FAILURE;
			    strcpy(tmp_1->word,token); //store the token in the word
			    tmp_1->file_count++;

			    if((tmp_1->file_table = create_sll() )== NULL)
				return FAILURE;
			    tmp_1->file_table->word_count++;
			    tmp_1->file_table->file_name = flist[i];  


			    tmp_4->link = tmp_1;
			}

		    }


		}




		/*----------------------------------------CASE 3: same word and same file/diffrent file --------------------------------------------------------------------*/

		else if((strcmp(db_ary[indx].word,token)) == 0)     // check word and data base word is same
		{

		    if(strcmp(db_ary[indx].tab_link->file_name , flist[i] ) == 0)      //first file
			db_ary[indx].tab_link->word_count++;

		    tmp = db_ary[indx].tab_link;


		    while(tmp->tab_link != NULL)
		    {
			tmp = tmp->tab_link;
			if( strcmp(tmp->file_name, flist[i]) == 0)
			    tmp->word_count++;
		    }

		    if(tmp->tab_link == NULL)
		    {
			if(strcmp(tmp->file_name ,flist[i]) != 0)
			{
			//		    printf("%d\t%s\n",db_ary[indx].file_count, token);
			    db_ary[indx].file_count++;
			    if( (tmp->tab_link = create_sll() ) != NULL)
			    {
				tmp->tab_link->word_count++;
				tmp->tab_link->file_name = flist[i];
			    }
			}
		    }
		}








	    } //endofif

	    token = strtok(NULL,"  \n");
	}//endofwhile
	fclose(fptr);
	fptr = NULL;
	j = 0;


    }//endofofr

    //---------------------------------------------------------------------------------------------------------------------------------------


    return SUCCESS;

}




