#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdio.h>

#include <string.h>

#include <conio.h>

#include <stdlib.h>

int main() {
  int i = 0, count = 0;
  FILE * fp;
  char ch;
  fp = fopen("lines.txt", "a+");
  if (fp == NULL) {
    printf("file doesnot exist");
    return 0;
  }
    ch = getch();
	while (ch == 'y') {

      char a[50];
      printf("enter anything?:");
      scanf("%s", a);
      fflush(stdin);
      fprintf(fp, "%s\n", a);
      printf("do you want to enter another line?:");
      ch = getche();
    }
    rewind(fp);
    char b[50];
	if (ch != 'y'){
	    while (fscanf(fp, "%s", b) != EOF) {
	        count++;
	    }
    }
	printf("no of lines=%d", count);
}
