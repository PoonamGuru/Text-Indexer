#include"main.h"
char ** input_from_user(int no_file)
{
    char **file_name ;
    int i;
    char temp[20];

    /*allocate the 1D array of char pointer*/
    file_name = malloc((no_file + 1) * sizeof(char *));

    for(i=0;i<no_file;i++)
    {
	puts("Enter the file_name:");
	scanf("%s%*c",temp);
	file_name[i] = malloc(strlen(temp+1));
	strcpy(file_name[i],temp);
    }

    file_name[no_file]  = NULL;
    for(i = 0; i < no_file; i++)
	printf("%s\n",file_name[i]);
    return file_name;
}
