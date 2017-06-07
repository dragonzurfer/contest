#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define up upper_bound
#define vll vector<ll>
#define G vector<vll >
#define F first
#define S second
#define pll pair<ll,ll>
#define FOR1(i,a) for(i=0;i<=a;i++)
#define FOR2(i,a,b) for(i=a;i<=b;i++)
#define endl '\n'
#define clr(a) memset(a,0,sizeof(a))
#define all(x) x.begin(),x.end()

typedef long long ll;
// ll read_ll(){char c=gc();while((c<'0'||c>'9')&&c!='-')c=gc();ll ret=0;int neg=0;if(c=='-')neg=1,c=gc();while(c>='0'&&c<='9'){ret=10*ret+c-48;c=gc();}return neg?-ret:ret;}

int main()
{
	ll n,m,i;
	cin>>n;
	ll sum=0,t;
	int p;
	FOR1(i,n-1)
	{
		cin>>t;
		sum+=t;
	}
	vll range;
	cin>>m;ll t2;
	FOR1(i,m-1)
	{
		cin>>t>>t2;
		range.pb(t);
		range.pb(t2);
	}
	auto k=lb(all(range),sum);
	ll low=k-range.begin();
	// cout<<low<<" "<<sum;
	// cout<<"DONE";

	if(k==range.end())
		cout<<"-1";
	else
	if(sum>t2)
		cout<<"-1";
	else
	if((sum<=range[low])&&(low+1)%2)
	{
		// cout<<"1";cin>>p;
		cout<<range[low];
	}
	else if(sum<=range[low]&&(low+1)%2==0)
	{
		// cout<<"2";cin>>p;
		cout<<sum;
	}
	else
		cout<<"-1";

	return 0;
}
