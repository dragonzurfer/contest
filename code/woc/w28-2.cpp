#include<bits/stdc++.h>
#define intmin 32
typedef long long ll;
using namespace std;

int main()
{
	ll q;
	cin>>q;
	while(q--)
	{
		ll n,cnt=0,ans=0;
		bool bit,first=false,start=false;cin>>n;
		for(int i = intmin-1,k=0; i >=0; i--,k++)
		{
			bit=n&(1<<i);
			cnt+=1;
			if(bit&&!first)
			{
				first=false;
				start=true;
			}

			if(!bit&&start)
			{
				ans+=pow(2,i);
				//cout<<i;
			}
		}
		cout<<ans<<endl;
		
		
		
	}
}