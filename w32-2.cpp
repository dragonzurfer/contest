#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define vll vector<ll>
#define F first
#define S second
#define pll pair<ll,ll>
#define FOR1(i,a) for(i=0;i<=a;i++)
#define FOR2(i,a,b) for(i=a;i<=b;i++)
#define endl '\n'
#define clr(a) memset(a,0,sizeof(a))
#define all(x) x.begin(),x.end()
typedef long long ll;

int main()
{
	ll n,i,t,tt;
	float val,hit;cin>>n>>hit>>t;
	ll a[n];
	FOR1(i,n-1)
	{
		cin>>val;
	a[i]=ceil(val/hit);
	}
	sort(a,a+n);
	ll cnt=0;
	tt=0;
	while(tt+a[cnt]<=t){//cout<<a[cnt]<<" ";
	tt=tt+a[cnt],cnt+=1;}

	cout<<cnt;
	return 0;
}