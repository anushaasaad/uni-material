#include <Stdio.h>
struct scheme{
	int judge;
	int players[5];
	
}s[5];
int main()
{
	struct scheme s[5];
	int i,mvp[5],max=0;
	for(i=1; i<=5; i++){
		printf("enter marks assigned by judges to student[%d]",i);
		scanf("%d",&s[i].judge);
	}
	for(i=1; i<=5; i++){
		mvp[i]=s[i].judge;
	printf("STUDENT[%d]=%d\n",i,mvp[i]);
   }
   for(i=2; i<=5; i++){
   	max=mvp[1];
   	if(mvp[i]>max){
   		max=mvp[i];
	   }
}
    printf("the student who won[%d]=%d\n",i,max); 
}
