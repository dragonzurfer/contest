#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define vll vector<ll>
#define first F
#define second S
#define pll pair<ll,ll>
#define FOR1(i,a) for(i=0;i<=a;i++)
#define FOR2(i,a,b) for(i=a;i<=b;i++)
#define endl '\n'
#define clr(a,v) memset(a,v,sizeof(a))
#define all(x) x.begin(),x.end()
typedef long long ll;


int main()
{
	ll test;
	cin>>test;
	while(test--)
	{
		ll n,i,j,ele;
	
	cin>>n>>ele;
	ll thres[ele];
	FOR1(i,ele-1)
	{
		cin>>thres[i];
	}
	ll sum[ele];
	// memset(sum,1,sizeof(sum));
	FOR1(i,ele-1)
	sum[i]=1;
	ll totalsum=ele;
	vll lis[ele];

	FOR1(i,ele-1)
	{
		lis[i].pb(1);
	}
	ll temp=0;

	//cout<<"-------------"<<sum[0]<<sum[1]<<"\n";
	//	for(auto&k:lis){
	//		for(auto&m:k)
	//			cout<<m<<"->";cout<<endl;
	//	}
	//	int t;cin>>t;
	FOR2(i,1,n-1)
	{
		temp=totalsum;
		FOR1(j,ele-1)
		{
			
			ll newnode=(totalsum-sum[j]+mod)%mod;
			lis[j].pb(newnode);
			temp=(temp+newnode)%mod;
			sum[j]=(sum[j]+newnode)%mod;
			if(lis[j].size()>thres[j])
			{
				ll tobecutnode=lis[j].at(lis[j].size()-thres[j]-1);
				//lis[j].pop_back();
				temp=(temp - tobecutnode+mod)%mod;
				sum[j]=(sum[j]-tobecutnode+mod)%mod;
			}
			sum[j]=sum[j]%mod;

		}

		//cout<<"-------------";
		//for(auto&k:lis){
		//	for(auto&m:k)
		//		cout<<m<<"->";cout<<endl;
		//}
		//cin>>t;
		totalsum=temp;
	}
	cout<<totalsum<<endl;
	//int t;cin>>t;
	}
	
	return 0;
}