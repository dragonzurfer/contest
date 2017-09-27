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
#define RFOR(i,a,b) for(int i=a;i>=b;i--)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
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

const int N = 100005;
const int LN = 18;

vector<int> tree[N];
int lvl[N],finish[N],start[N],dp[N][LN],t=0;
bool visited[N];

void dfs(int u,int p)
{
	visited[u] = true;
	start[u] = t++;
	FOR(i,1,LN-1) dp[u][i] = dp[dp[u][i-1]][i-1];
	for(auto v:tree[u])
	{
		if(visited[v]) continue;
		lvl[v] = lvl[u] + 1;
		dp[v][0] = u;
		dfs(v,u);
	}
	finish[u] = t++;
}

int lca(int u,int v)
{
	if(lvl[u]>lvl[v]) swap(u,v);

	RFOR(i,LN-1,0)
	if(lvl[v]-(1<<i)>=lvl[u])
		v = dp[v][i];
	if(u==v) return u;
	RFOR(i,LN-1,0)
	if(dp[u][i]!=dp[v][i])
		v = dp[v][i], u = dp[u][i];
	return dp[u][0];
}

int dist(int u,int v)
{
	// cout<<lvl[u]<<endl<<lvl[v]<<endl<<lvl[lca(u,v)]<<endl<<"lca:"<<lca(u,v)<<endl;
	return (lvl[u]+lvl[v]-2*lvl[lca(u,v)]);
}

bool isancestor(int u,int v)
{
	if(u == v) return true;
	if(lvl[v]>lvl[u])return false;
	if(start[v]<start[u]&&finish[v]>finish[u])
		return true;
	return false;
}

int cal(int s,int t,int f)
{
	// number of nodes that t->f intersect with in path from s->f
	int u = lca(s,f);
	int v = lca(s,t);
	int x = lca(t,f);
	
	if(isancestor(v,u))
	{
		if(isancestor(x,v))
			return dist(x,f);
	
		else
			return dist(v,f);
	
	}else if(isancestor(u,v))	
		return dist(u,f);
}

void test(int n)
{
	FOR(s,1,n)
	{
		FOR(t,1,n)
		{
			if(s==t)continue;
			FOR(f,1,n)
			{
				if(t==f || f == s)continue;
				cout<<' '<<s<<"->"<<f<<" & "<<t<<" : "<<cal(s,t,f)<<endl;
			}
		}
	}
}

int main()
{
	int n,q,v;
	n = rll;
	q = rll;
	FOR(u,2,n)
	{
		v = rll;
		tree[u].pb(v);
		tree[v].pb(u);
	}

	clr(visited);
	lvl[1] = 0;
	dp[1][0] = 1;
	dfs(1,-1);

	//test(n);

	while(q--)
	{
		int k,l,m;
		cin>>k>>l>>m;
		vector<int>v(6);
		v[0] = cal(k,l,m)+1;
		v[1] = cal(k,m,l)+1;
		v[2] = cal(l,k,m)+1;
		v[3] = cal(l,m,k)+1;
		v[4] = cal(m,k,l)+1;
		v[5] = cal(m,l,k)+1;
		sort(v.begin(),v.end());
		cout<<v[5]<<endl;
	}
	return 0;
}