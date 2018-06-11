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
#define RFOR(i,a,b) for(i=a;i>=b;i--)
#define FOR(i,a,b) for(i=a;i<=b;i++)
#define endl '\n'
#define clr(a) memset(a,0,sizeof(a))
#define all(x) x.begin(),x.end()
#define rll read_ll();
#define gc getchar
#define pc putchar
#define deb2(a,b,c,d) cout<<a<<":"<<b<<" "<<c<<":"<<d<<endl;
typedef long long ll;
template<class T> inline T lcm(T a,T b){
        return a/gcd(a,b)*b;
}

ll read_ll(){char c=gc();while((c<'0'||c>'9')&&c!='-')c=gc();ll ret=0;int neg=0;if(c=='-')neg=1,c=gc();while(c>='0'&&c<='9'){ret=10*ret+c-48;c=gc();}return neg?-ret:ret;}

const ll N=100;
string s;
ll le[8*N],ri[8*N],t[4*N];
int NEXT_FREE_NODE=0,n;

ll newnode(ll val)
{
	int p=NEXT_FREE_NODE++;
	le[p]=ri[p]=0;
	t[p]=val;
	return p;
}

void update(int id)
{
	t[id]=t[le[id]]+t[ri[id]];
}

ll newparent(ll left,ll right)
{
	int p=NEXT_FREE_NODE++;
	le[p]=left;
	ri[p]=right;
	update(p);
	return p;
}

ll init(ll l=0,ll r=n-1)
{
	int m=(l+r)/2;
	if(r-l<2)
		return newnode(0);
	else
		return newparent(init(l,m),init(m,r));
}

ll increment(int i,int ind,int val,ll l=0,ll r=n-1)
{
	if(r-l<2)
	{
		return newnode(t[i]+val);
	}
	int m=(l+r)/2;
	if(ind<=m) return newparent(increment(le[i],ind,val,l,m),ri[i]);
	else return newparent(le[i],increment(ri[i],ind,val,m,r));
}

//[l,r)
ll query_tree(ll x,ll y,ll i,ll l=0,ll r=n-1)
{
	if(l>r)swap(l,r);
	// deb2("l",l,"r",r);int tt;cin>>tt;
	if(r<x || y<l )return 0;
	if(x<=l&&r<=y) 
	{
		return t[i];
	}
	int m=(l+r)/2;
	return query_tree(x,y,le[i],l,m)+query_tree(x,y,ri[i],m+1,r);
}

bool cmp(ll a, ll b )
{
	return a>b;
}

int main()
{
	ll n;
	n=rll;
	ll a[n];
	init(0,n-1);
	int i;
	FOR(i,0,n-1)
	a[i]=rll;

	ll root[n];
	root[0]=0;
	FOR(i,0,n-1)
	{
		root[i+1]=increment(root[i],a[i],1);
	}

	for(auto&k:root)
		cout<<k<<" ";cout<<endl;
	ll l,r,q,v;

	q=rll
	while(q--)
	{
		l=rll r=rll v=rll
		auto p=query_tree(0,v,root[r])-query_tree(0,v,root[l]);
		cout<<p<<endl;
	}

	return 0;
}