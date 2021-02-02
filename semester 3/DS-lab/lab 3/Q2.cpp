using namespace std;
#include <iostream>
#include <vector>

int main(){
	int a, k, i,j;
	std::vector < vector <int> > vec;
	for (i=0; i<3; i++){
		std::vector<int> t;
		cout<<"enter size of rows" <<endl;
		cin>>k;
		for(j=0; j<k; j++){
			cout<<"enter elements of rows:" <<endl;
			cin>>a;
			t.push_back(a);
		}
		vec.push_back(t);
	}
	for(i=0; i<3; i++){
		cout<<"\n"; 
		k=vec[i].size();
		for ( j = 0; j < k; j++)
		{
			cout<< vec[i][j] <<" ";
		}		
	}
}

