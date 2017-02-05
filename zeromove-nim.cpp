#include<bits/stdc++.h>
using namespace std;


int main(){
  long long int g,n;

  cin>>g;
  while(g--)
  {
  	cin>>n;
  	long long int a[n];
  	for(int i=0;i<n;i++)
  		cin>>a[i];
  	
  	long long int g[n];
    for(int i=0;i<n;i++)
      if(a[i]%2)
      g[i]=a[i]+1;
      else
      g[i]=a[i]-1;
  	int x=0;
  	for(int i=0;i<n;i++)
  	{
  		x=x^g[i];
  	}

  	if(x)
    {
      cout<<"W"<<endl;
    }
    else
      {
      cout<<"L"<<endl;
    }
  }
    return 0;
    
}