#include<bits/stdc++.h>
using namespace std;
int main()
{
int n,c,m,i=0;
cin>>n>>c>>m,c*=m;
while(n--){
cin>>i;
if(c<i)
cout<<"No",exit(0);
}
cout<<"Yes";
}
