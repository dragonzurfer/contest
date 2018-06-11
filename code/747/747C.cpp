#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
	ll n,q,k,t,d;
	cin>>n;
	int servers[n],ti=0,temp,sum;
	for(int i=0;i<n;i++)
		servers[i]=0;
	stack<int>f;
	cin>>q;
	while(q--)
	{
		
		cin>>t>>k>>d;
		ti=t-ti;
		temp=0;
		sum=0;
		for(int i=0;i<n;i++)
			if(servers[i]<=t&&temp!=k)
				temp+=1,f.push(i);

		if(temp<k){
			while(!f.empty())
				f.pop();
			cout<<"-1"<<endl;
		}
		else
		{
			
			while(!f.empty()){
				servers[f.top()]=t+d;
				sum+=f.top()+1;
				f.pop();
			}
			cout<<sum<<endl;
		}
		//cout<<endl;
		//for(int i=0;i<n;i++)
		//	cout<<servers[i]<<" ";
	}	
	return 0;
}