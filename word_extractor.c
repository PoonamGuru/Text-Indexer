#include"main.h"

char * word_extractor(FILE *fptr)
{
    char ch;
    static char word[20];
    int i =0, j = 0;

  while((ch = fgetc(fptr)) != EOF)
         {
             if((ch >= 'a' && ch <= 'z') ||(ch >= 'A' && ch <= 'Z'))
             {
                 word[j]=ch;
                 j++;
             }
 
             else
             {
                 word[j] = '\0';
                 j=0;
             }
 
         }

  return word;




}
