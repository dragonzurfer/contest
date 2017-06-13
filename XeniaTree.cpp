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


typedef long long ll;

template<class T> inline T lcm(T a,T b){
        return a/gcd(a,b)*b;
}

ll read_ll(){char c=gc();while((c<'0'||c>'9')&&c!='-')c=gc();ll ret=0;int neg=0;if(c=='-')neg=1,c=gc();while(c>='0'&&c<='9'){ret=10*ret+c-48;c=gc();}return neg?-ret:ret;}
const int N=100005;
const int LN=18;

ll level[N],dp[N][LN],sub[N],par[N],ans[N],tn;
set<ll> g[N];

void dfs(ll u,ll p)
{
	int i;
	FOR(i,1,LN-1) dp[u][i]=dp[dp[u][i-1]][i-1];
	for(auto v=g[u].begin();v!=g[u].end();++v)
	{
		if(*v!=p)
		{
			dp[*v][0]=u;
			level[*v]=level[u]+1;
			dfs(*v,u);
		}
	}
}

ll lca(ll u,ll v)
{
	int i;
	if(level[v]>level[u])swap(u,v);
	RFOR(i,LN-1,0)
	if(level[u]-(1<<i)>=level[v])
		u=dp[u][i];
	if(u==v)return u;
	// cout<<"u:"<<u;cin>>i;
	RFOR(i,LN-1,0)
	if(dp[u][i]!=dp[v][i])
		u=dp[u][i],v=dp[v][i];
	return dp[u][0];
}

ll dfs1(ll u,ll p)
{
	sub[u]=1;
	tn++;
	for(auto v=g[u].begin();v!=g[u].end();++v)
	{
		if(*v!=p)
		{
			dfs1(*v,u);
			sub[u]+=sub[*v];
		}
	}
}

ll dfs2(ll u,ll p)
{
	for(auto v=g[u].begin();v!=g[u].end();v++)
		if(*v!=p&&sub[*v]>tn/2)
			return dfs2(*v,u);
	return u;
}

void CentroidDecompose(ll root,ll p)
{
	tn=0;
	dfs1(root,root);
	// cout<<"OK";int test;cin>>test;
	ll centroid=dfs2(root,root);
	// cout<<endl<<centroid<<" <-"<<p<<" ";
	if(p==-1) p=centroid;
	par[centroid]=p;
	for(auto v=g[centroid].begin();v!=g[centroid].end();++v)
		g[*v].erase(centroid),CentroidDecompose(*v,centroid);
	g[centroid].clear();
}
ll dist(ll u,ll v)
{
	return level[u]+level[v]-2*level[lca(u,v)];
}
void update(ll u)
{
	ll x=u;
	while(1)
	{
		ans[x]=min(ans[x],dist(u,x));
		if(x==par[x])break;
		x=par[x];
	}
	// return ret;
}
ll query(ll u)
{
	ll x=u;
	ll ret=INT_MAX;
	while(1)
	{
		// cout<<"ret:"<<ret<<" dist(u,x)+ans["<<x<<"]:"<<ans[x];int t;cin>>t;
		ret=min(ret,ans[x]+dist(u,x));
		if(x==par[x])break;
		x=par[x];
	}
	return ret;
}
int main()
{
	ll n,m,i,u,v,type;
	n=rll m=rll
	FOR(i,0,n-2)
	{
		u=rll v=rll
		g[u].insert(v);
		g[v].insert(u);
	}
	FOR(i,1,n)
	ans[i]=INT_MAX;
	level[1]=0;
	dp[1][0]=1;
	dfs(1,-1);
	CentroidDecompose(1,-1);
	update(1);
	// for(int i=0;i<10;i++)
	// 	cout<<par[i]<<" ";
	
	// cout<<"OK";int test;cin>>test;
	while(m--)
	{
		type=rll
		v=rll
		// cout<<dist(type,v);
		if(type==1)
			update(v);
		else
			cout<<query(v)<<endl;
	}
	return 0;
}