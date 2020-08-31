#include <stdio.h>

main () 
{
	int id, u;
	char name[10];
	float amucharge, amcharge, surcharge, netamu;
	
	printf("what is the customer ID? ");
	scanf("%d",&id);
	
	printf("Customer Name: ");
	scanf("%s", &name);
	
	printf("enter the unit consumed? ");
	scanf("%d", &u);
	
	if(u<199)
		amucharge=1.20;
	else if(u>=200 && u<400)
		amucharge=1.50;
	else if(u>=400 && u<600)
		amucharge=1.80;
	else
		amucharge=2.00;
	 
	amcharge=u*amucharge;
	 
	if(amcharge>400)
		surcharge=amcharge*15/100;
	
	netamu=amcharge+surcharge; 
	printf("ELECTRICITY BILL\n");
	
	printf("customer ID=%d\n",id);
	
	printf("customer First name letter= %s\n",name);
	
	printf("unit consumed=%d\n",u);
	
	printf("amount charges per unit %f is %f \n",amucharge ,amcharge);
	
	printf("surcharge amount is %f \n",surcharge);
	
	printf("net amount paid by the customer is %f \n",netamu);
	
}
