#include<stdio.h>

struct Student
{
	int a;
	int c;
	float b;
};

PassArray(int *ptr2)
{
	printf("\n");
	int i;

	for(i=0; i<5; i++)
	{
		printf("%d", ptr2[i]);
	}

}

int* MinMaxFromArray (int *ptr)
{
	static int a[2]; //Why static? Discussed in class.
	int i;
	int max = 0, min = *ptr;
	
	for(i=0; i<5; i++)
	{
		if(max<*ptr)
		max = *ptr;
		
		
		if(min>*ptr)
		min = *ptr;
		
		ptr++;
	}
	
	a[0] = max;
	a[1] = min;
	
	return a;
}

PassStructArray(struct Student *s)
{
	int i;
	for(i=0; i<2; i++)
	{
	printf("\n%d\n", s->a);
	printf("%f\n", s->b);
	printf("%d\n", s->c);
	s++;
	}
}

struct Student* ReturnStructArrayFromFuntion(struct Student *m)
{
	int i;
	static struct Student s[2];
	for(i=0; i<2; i++)
	{
	s[i].a = m->a;
	s[i].b = m->b;
	s[i].c = m->c;
	m++;
	}
	
	return s;
}
	

int main()
{
	int *ptr1;
	int *ptr2;
	int a[5] = {5,8,3,9,2};
	
	ptr1 = a; //Also ptr1 = &a[0]
	
	//Accessing the array through pointer
	//Method1
	int i;
	for(i=0; i<5; i++)
	{
		printf("%d", *ptr1);
		ptr1++;
	}
	
	printf("\n");
	
	//Method2
	ptr1 = a;
	for(i=0; i<5; i++)
	{
		printf("%d", *(ptr1+i));
	}
	
	printf("\n");
	
	//Method3
	ptr1 = a;
	for(i=0; i<5; i++)
	{
		printf("%d", ptr1[i]);
	}
	
	ptr1 = a;
	PassArray(ptr1); 
	
	ptr2 = MinMaxFromArray (ptr1); //==PassArray(a) ==PassArray(&a[0). All of them are correct. 
	
	printf("\n");
	for(i=0; i<2; i++)
	{
		printf("%d", ptr2[i]);
	}
	
	struct Student s[2];
	
	s[0].a = 1;
	s[0].b = 1.5;
	s[0].c = 6;
	
	s[1].a = 4;
	s[1].b = 4.5;
	s[1].c = 8;
	
	
	int *ptr3;
	
	ptr3 = s;
	
	printf("\n");
	printf("%d", *ptr3); //observe the output
	ptr3++;
	printf("\n");
	printf("%d", *ptr3); //observe the output
	ptr3 = ptr3+2;
	printf("\n");
	printf("%d", *ptr3); //observe the output
	
	//So for pointing a structure array we need a structure type pointer
	
	struct Student *ptr, *ptrr;
	
	ptr = s;
	printf("\n");
	printf("%d\n", ptr->a); //Observe the syntax here
	printf("%f\n", ptr->b);
	printf("%d\n", ptr->c);
	
	ptr++;
	
	printf("\n");
	printf("%d\n", ptr->a);
	printf("%f\n", ptr->b);
	printf("%d\n", ptr->c);
	
	ptr = s;
	ptrr = ReturnStructArrayFromFuntion(ptr);
	PassStructArray(ptr);
	
	for(i=0; i<2; i++)
	{
	printf("\n%d\n", ptrr->a);
	printf("%f\n", ptrr->b);
	printf("%d\n", ptrr->c);
	ptrr++;
	}
	
	getch();
}
