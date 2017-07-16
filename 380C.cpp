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
const ll N=1000000;
string s;
ll lo[4*N],hi[4*N],valid[4*N],open[4*N],closed[4*N];
void init(ll i,ll a,ll b)
{
	lo[i]=a;
	hi[i]=b;
	if(a==b)
	{
		valid[i]=0;
		if(s[a]==')')
			closed[i]=1;
		else
			open[i]=1;
		return;
	}
	int m=(a+b)/2;
	init(2*i,a,m);
	init(2*i+1,m+1,b);
	ll vv=min(open[2*i],closed[2*i+1]);
	valid[i]=valid[2*i]+valid[2*i+1]+vv;
	closed[i]=closed[2*i]+closed[2*i+1]-vv;
	open[i]=open[2*i]+open[2*i+1]-vv;
}

void increment(ll i,ll a,ll b,ll val)
{
	if(b<lo[i] || hi[i]<a )return;

	if( a<=lo[i] && hi[i]<=b)
	{
		
		delta[i]+=val;
		return;
	}
	prop(i);
	increment(2*i,a,b,val);
	increment(2*i+1,a,b,val);
	update(i);
}

pair<ll,pair<ll,ll> > query_tree(ll i,ll a,ll b)
{
	if(a>b)swap(a,b);
	if(b<lo[i] || hi[i]<a )return mp(0,mp(0,0));

	if( a<=lo[i] && hi[i]<=b)
	{
		return mp(valid[i],mp(open[i],closed[i]));
	}
	pair<ll,pll> left=query_tree(2*i,a,b);
	pair<ll,pll> right=query_tree(2*i+1,a,b);
	ll vv,tt,top,tcl;
	tt=min(left.S.F,right.S.S);
	vv=left.F+right.F+tt;
	top=left.S.F+right.S.F-tt;
	tcl=left.S.S+right.S.S-tt;

	return mp(vv,mp(top,tcl));
}

int main()
{

	cin>>s;

	init(1,0,s.length()-1);
	ll l,r,q;
	q=rll
	while(q--)
	{
		l=rll r=rll
		l--;r--;
	auto p=query_tree(1,l,r);
	cout<<p.F*2<<endl;
	}

	return 0;
}