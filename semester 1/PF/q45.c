#include <stdio.h>
#include <string.h>
#define max_word 20
void pluralize (char word[]);


int main (void)
{ 
  char noun[max_word];   
  printf("Enter a noun in singular form: ");
  scanf("%s", noun);

  if (strcmp(noun, "done") != 0)
 {
    pluralize (noun);
    printf("The plural form is %s\n", noun);
 }
  return;
}
void pluralize (char word[])
{
  int length;
  char noun;
  length=1;
  length = strlen(word);

   if (word[length - 1] == 'e' && word[length -2]=='f' ) 
 {   word[length - 2] = 'v';
    word[length] = 's';
    word[length +1] = '\0';  
  }
else if (word[length - 1] == 's' ||
    (word[length - 2] == 'c' && word[length - 1] == 'h') ||
    (word[length - 2] == 's' && word[length - 1] == 'h'))
  {  strcat(word, "es");
  }

  else
 {   strcat(word, "s");

    printf("New word is: ", &noun);
} 

}
