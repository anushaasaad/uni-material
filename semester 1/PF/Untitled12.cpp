#include <stdio.h>
int main()
{
	char a[100];
	int loop,b=0,c=0,d=0,e=0,f=0,g=0,h=0,i=0,j=0,k=0;
	printf("enter anything?:");
    scanf("%s",a);
    for(loop=0; loop!='\0'; loop++){
    	
		if(a[i]=='b'){
    		b++;
		}
	    if(a[i]=='c'){
    		c++;
		}
		if(a[i]=='d'){
    		d++;
		}
		if(a[i]=='e'){
    		e++;
		}
		if(a[i]=='f'){
    		f++;
		}
		if(a[i]=='g'){
    		g++;
		}
		if(a[i]=='h'){
    		h++;
		}
		if(a[i]=='i'){
    		i++;
		}
		if(a[i]=='j'){
    		j++;
		}
		if(a[i]=='k'){
    		k++;
		}
	}
	printf("a=%d\nb=%d\nc=%d\nd=%d\ne=%d\nf=%d\ng=%d\nh=%d\ni=%d\nj=%d\nk=%d",b,c,d,e,f,g,h,i,j,k);
}
