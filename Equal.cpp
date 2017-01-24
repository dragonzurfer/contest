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
#define test(t) while(t--)
typedef long long ll;


int main()
{
	ll t,n,i,j;cin>>t;
	test(t)
	{
		cin>>n;
		ll a[n];
		FOR(i,0,n-1)
		{
			cin>>a[i];
			
		}
		ll min=*min_element(a,a+n);
		ll ans[6];
		clr(ans);
		FOR(j,0,5)
		{
			FOR(i,0,n-1)
			{
				ll t=abs(a[i]-(min-j));
				ll x=t/5+(t%5)/2+(t%5)%2;
				ans[j]+=(x);
			}
		}

		cout<<*min_element(ans,ans+6)<<endl;
	}
	return 0;
}