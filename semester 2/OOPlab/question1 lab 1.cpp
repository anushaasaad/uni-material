#include <iostream>
#include <string>
# include <iomanip>
using namespace std;
int main()
{
	double kilo;
	float pounds=2.2;
	cout<<fixed<<showpoint<<setprecision(2);
	cout<<"enter kilograms:" <<endl;
	cin>>kilo;
	pounds*=kilo;
	cout<<"pounds in " <<kilo <<" kilograms is:"<<pounds <<endl;
	return 0;
}
