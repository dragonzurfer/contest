#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
	ll n;cin>>n;
	ll a[n];

	ll lastr=1,cnt=0;

	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]==0)
			cnt+=1;
	}


	if(cnt==n)
	{
		cout<<"NO";exit(0);
	}
	else
	{
		cout<<"YES"<<endl;
	}

	vector<pair<ll,ll> >ans;
	ll l=0,r=0;

	for(int i=0;i<n;i++)
	{		
		if(a[i])
		{
			if(ans.size())
			ans.push_back(make_pair(ans.back().second+1,r+1));
			else
				ans.push_back(make_pair(1,r+1));

			lastr=r+1;
		}
		r+=1;
	}
	
	if(ans.size()&&ans.back().second!=n)
	{
		ans.back().second=n;
	}

	cout<<ans.size()<<endl;

	for(auto&i:ans)
		cout<<i.first<<" "<<i.second<<endl;

	return 0;
}