#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define vl vector<ll>
#define first F
#define second S
#define pll pair<ll,ll>
#define FOR(i,a,b) for(i=a;i<=b;i++)
#define endl '\n'
#define clr(a) memset(a,0,sizeof(a))
typedef long long ll;


int main()
{
	ll n,i,t;

	cin>>n;
	vector<ll> a;

	FOR(i,0,n-1)
	cin>>t,a.pb(t);

	ll sum[n];

	FOR(i,0,n-1)
	sum[i]=1;

	ll ans=0;

	FOR(i,1,n-1)
	{
		if(a[i]>a[i-1])
			sum[i]=sum[i-1]+1;
	}

	ans=sum[n-1];
	for(i=n-2;i>=0;i--)
	{
		if(a[i]>a[i+1])
			sum[i]=max(sum[i],sum[i+1]+1);
		ans+=sum[i];
	}

	cout<<ans;
	return 0;
}