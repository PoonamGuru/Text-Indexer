#include"main.h"
int display_data_base(data_base * db_ary)
{

    int i = 0;
    file_table * tmp;
    Slist * tmp_1;
   //printf("file_count\t\tword\t\t    \t\tword_count\t\t file_name\t\t word_count\t\tfile_name\n");

    for(i = 0; i < SIZE; i++)
    {
	if(db_ary[i].word[0] != '\0')
	{
	    printf("%d\t",db_ary[i].file_count);
	    printf("%s\t",db_ary[i].word);
         
	
	    tmp = db_ary[i].tab_link;

	    while(tmp != NULL)
	    {
		printf("%d\t%s\t",tmp->word_count,tmp->file_name);
		tmp = tmp->tab_link;
	    }
	    puts("");


	    tmp_1 = db_ary[i].link;
	    while(tmp_1 != NULL)
	    {
		printf("%d\t%s\t",tmp_1->file_count, tmp_1->word);

		tmp = tmp_1->file_table;
		while(tmp != NULL)
		{
		    printf("%d\t%s\t",tmp->word_count, tmp->file_name);
		    tmp = tmp->tab_link;
		}
		puts("");
		tmp_1 = tmp_1->link;
	    }




	}
    }
}
