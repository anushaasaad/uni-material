#include <bits/stdc++.h>
#
using namespace std;

int main()

{

    int n;

    cin>>n;

    int count = 0;

    int i = 0;

    queue<int> s;

    vector<int> a(n);

    for(i = 0;i<n;i++)

    {

        int x;

        cin>>x;

        s.push(x);

    }

    for(i = 0;i<n;i++)

    cin>>a[i];

    


 

    for(i = 0;i<n;i++)

    {   while(s.front() != a[i])

        {

            int x = s.front();

            s.pop();

        

            s.push(x);

            count++;

            }

            s.pop();

    }

        

    

    count = count+n;

    cout<<count<<endl;

    return 0;

    
}

