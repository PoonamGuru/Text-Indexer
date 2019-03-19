#include"main.h"

int main()
{
    int option;       //to select the option
    char choice;      //to run application continuesly
    FILE * fptr = NULL;
    char ** flist;
    char ** old_flist;
    int i;
    int no_file;

    data_base db_ary[SIZE];
    do
    {
		system("clear");

	printf("1 create_database\n2 search\n3 display\n4 save_to_database\n5 update_data_base\n6 exit\nEnter the option:\n");
		scanf("%d%*c",&option);

	switch(option)
	{
	    case CREATE_DATABASE :
		{
		    puts("------------------------------------CREATE A DATABASE----------------------------------------------");
		    puts("Enter the no of files:");
		    scanf("%d%*c",&no_file);

		    if( (flist = input_from_user(no_file)) == NULL)
			return -1;
		    default_database(db_ary);        //create a new data base with default values


		    /*create data base*/
		    if(create_data_base(db_ary,flist,no_file) == SUCCESS)
			puts("data base created successfully");
		    else
			puts("data base is not created successfully");
		}
		break;

	    case DISPLAY_DATABASE:		
		display_data_base(db_ary);
		break;

	    case  UPDATE_DATABASE :
		{	
		    puts("------------------------------------UPDATE A DATABASE----------------------------------------------");
		    puts("Enter the no of files:");
		    scanf("%d%*c",&no_file);

		    old_flist = flist;
		    if( (flist = input_from_user(no_file)) == NULL)
			return -1;
		    int i = 0,j = 0 ; 
		    while(old_flist[i] != NULL)
		    {
			if(strcmp(flist[j] , old_flist[i]) == 0)
			{
			    printf("file already exits\n");
			    return 1;
			}

			i++;
		    }
		    if(create_data_base(db_ary,flist,no_file) == SUCCESS)
			puts("data base updated successfully");
		    else
			puts("data base is not updated successfully");
		}
		break;

	    case SEARCH :
		{
		    char s_data[10];
		    puts("/*-----------------------------SEARCH----------------*/");
		printf("Enter the word to be search :");
		scanf("%s%*c",s_data);

		if( search_data_base(db_ary, s_data) == 0)
		    puts("data found");
		}
		break;

	    case SAVE_DATABASE :
		{
		    char file_name[20];

		    puts("------------------------------------------------SAVE_DATABASE------------------------------------------------");
                    puts("Enter  the file name without extension:");
		    /*get the file name into which data to be stored*/
		    fgets(file_name,20,stdin);
		    file_name[strlen(file_name) - 1] = '\0';


		    /*call the save_database function */

		    if(save_database(file_name,db_ary) == SUCCESS)
		    {
			printf("data base is save into %s.csv successfully\n",file_name);
		    }
		    else
                 	printf("data base is save into %s.csv successfully\n",file_name);





		}
		break;
	    case EXIT : 
		puts("Exit from the application");
		return 0;

	    default:
		puts("Enter the proper option !!!");
	}


	puts("DO you want to contine [y/n] : ");
	scanf("%c%*c",&choice);
    }while(choice == 'y');




    return 0;
}
