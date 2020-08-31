#include <stdio.h>
struct customer
{
	int account;
	char name[200];
	int balance;
}c[200];
void below();
void withdrawl(int amount,int code);
int main()
{
	int i;
	for(i=0; i<200; i++){
	struct customer c[i]={
	1,"anusha",99,
	2, "anfaal",1001,
	3,"sharjeel",120,
	4,"hadiqa",82,
	5,"ahsan",1200,
};
};


	int account,code,amount;
	printf("enter account no");
	scanf("%d",&account);
	printf("enter ammount tobe withdrawled");
	scanf("%d",&amount);
	printf("enter code");
	scanf("%d",&code);		
	below();
	withdrawl(account,code);
}
void below()
{
	int i;
	for(i=0; i<200; i++){
	if(c[i].balance>100 && c[i].balance<0){
		printf("NAME:%c",c[i].name);
		printf("ACOUNT NO=%d",c[i].account);
	}
}
}
void withdrawl(int amount,int code)
{
	int deposit,i;
	for(i=0; i<200; i++){
	if(code==1){
		if(c[i].balance-amount<=100){
			printf("insufficient");
		}else{
			c[i].balance-=amount;
			printf("remaining amount=%d",c[i].balance);
		}
	}else{
		printf("enter amount to deposit");
		scanf("%d",&deposit);
		c[i].balance+=deposit;
	}
}
}
