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
#define rll read_ll();
typedef long long ll;
bool cmp(ll a,ll b)
{
	return a>b;
}
int main()
{
	ll n,i,k;
	cin>>n>>k;
	ll a[n],b[k];
	vll pos;
	FOR1(i,n-1)
	{

	cin>>a[i];
	if(a[i]==0){

		pos.pb(i);
	}
	}
	FOR1(i,k-1) cin>>b[i];
	sort(b,b+k,cmp);
	bool flag=false;
	ll o=0;
	for(auto&p:pos)
	{
		if(p>0&&(a[p-1]>=b[o]||(b[o]>=a[p+1])))
		{
			flag=true;break;
		}
		else if(p==0&&b[o]>=a[p+1]&&pos.size()>1)
		{

			flag=true;break;
		}
		else
		{
			a[p]=b[o];
		}
		o++;

	}
	if(!flag)
	FOR2(i,1,n-1)
	{
		if(a[i-1]>=a[i])
			{flag=true;break;}
	}
	if(flag)
		cout<<"Yes";
	else
		cout<<"No";

	return 0;
}