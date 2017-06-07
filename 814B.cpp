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
// ll read_ll(){char c=gc();while((c<'0'||c>'9')&&c!='-')c=gc();ll ret=0;int neg=0;if(c=='-')neg=1,c=gc();while(c>='0'&&c<='9'){ret=10*ret+c-48;c=gc();}return neg?-ret:ret;}

int main()
{
	ll i;
	ll n;cin>>n;
	ll a[n],b[n];
	FOR1(i,n-1)
	cin>>a[i];
	FOR1(i,n-1)
	cin>>b[i];
	map<ll,ll> hash;
	set<ll>anomaly;
	vector<pair<pair<ll,ll> ,ll> > pos;
	FOR1(i,n-1)
	{
		if(a[i]==b[i])
			hash[a[i]]=1;
		else
		{
			pos.pb(mp(mp(a[i],b[i]),i));
		}
	}
	ll fill[n];
	ll k=0;
	

	FOR2(i,1,n)
	{
		if(hash[i]==0)
			fill[k++]=i;
	}
	ll first=0,second=0;
	if(k==1)
	{
		a[pos[0].S]=fill[0];
		FOR1(i,n-1)
		cout<<a[i]<<" ";return 0;
	}
	else if(pos.size()>1)
	{

		ll A=pos[0].F.F,B=pos[0].F.S,C=pos[1].F.F,D=pos[1].F.S;
		if(k==2)
		{
			if(!hash[B]&&!hash[C]&&B!=C)
				first=C,second=B;
			else if(!hash[C]&&!hash[A]&&C!=A)
				first=C,second=A;
			else if(!hash[B]&&!hash[D]&&B!=D)
				first=D,second=B;
			else if(!hash[A]&&!hash[D]&&A!=D)
				first=D,second=A;
			if(B!=first||A!=first)
				swap(first,second);
		}
		else
		{
		if(A==C)
			first=A,second=D;
		else if(A==D)
			first=A,second=C;
		else if(B==C)
			first=B,second=D;
		else if(B==D)
			first=B,second=C;
	}
	// cout<<first<<" "<<second<<endl;
		a[pos[0].S]=first;
		a[pos[1].S]=second;
		FOR1(i,n-1)
		cout<<a[i]<<" ";return 0;

	}

	
	
	FOR1(i,n-1)
	{

	}


	return 0;
}