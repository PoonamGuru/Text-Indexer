#include"main.h"

int search_data_base(data_base db_ary[], char * s_data)
{
    file_table * tmp;
    Slist * tmp_1;
    int indx = hash_indx(s_data); // find the index of the word

    printf("indx = %d\n",indx);


    if( str_cmp(db_ary[indx].word,s_data) == 0)
    {
	printf("%s\t",db_ary[indx].word);

	tmp = db_ary[indx].tab_link;

	while(tmp != NULL)
	{
	    printf("%d\t%s\n",tmp->word_count, tmp->file_name);  //print the wordcout and file name

	    tmp = tmp->tab_link;

	    printf("%p\n",tmp);
	}

    }
    else
    {


	tmp_1 = db_ary[indx].link;

	while(tmp_1 != NULL)
	{
	    if ( str_cmp(tmp_1->word, s_data) == 0 )
	    {
		printf("%s\t", tmp_1->word);


		tmp = tmp_1->file_table;
		while(tmp != NULL)
		{
		    printf("%d\t%s\t",tmp->word_count, tmp->file_name);
		    tmp = tmp->tab_link;
		}
		puts("");
	    }

	    tmp_1 = tmp_1->link;
	}




    }

    }
