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
typedef int ll;
template<class T> inline T lcm(T a,T b){
        return a/gcd(a,b)*b;
}

ll read_ll(){char c=gc();while((c<'0'||c>'9')&&c!='-')c=gc();ll ret=0;int neg=0;if(c=='-')neg=1,c=gc();while(c>='0'&&c<='9'){ret=10*ret+c-48;c=gc();}return neg?-ret:ret;}
const ll N=10005;
const ll LN=15;

struct edge
{
	ll c,val;
};

ll chead[N],cindex[N],basearray[N],posInBase[N],size[N],p[N][LN],lvl[N];

ll lo[4*N],hi[4*N],delta[4*N],maxi[4*N];
void init(ll i,ll a,ll b)
{
	lo[i]=a;
	hi[i]=b;
	if(a==b)
		return;
	int m=(a+b)/2;
	init(2*i,a,m);
	init(2*i+1,m+1,b);
}

void prop(ll i)
{
	delta[2*i]+=delta[i];
	delta[2*i+1]+=delta[i];
	delta[i]=0;
}

void update(ll i)
{
	maxi[i]=max(maxi[2*i]+delta[2*i],maxi[2*i+1]+delta[2*i+1]);
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

ll query_tree(ll i,ll a,ll b)
{
	if(a>b)swap(a,b);
	if(b<lo[i] || hi[i]<a )return INT_MIN;

	if( a<=lo[i] && hi[i]<=b)
	{
		return maxi[i]+delta[i];
	}
	prop(i);
	ll left=query_tree(2*i,a,b);
	ll right=query_tree(2*i+1,a,b);
	update(i);

	return max(left,right);
}

void dfs(vector< edge>g[],ll u,ll par)
{
	int i;
    p[u][0]=par;
    size[u]=1;
	FOR(i,1,LN-1)
	p[u][i]=p[p[u][i-1]][i-1];
	for(auto&v:g[u])
	{
		if(v.val!=par)
		{
			lvl[v.val]=lvl[u]+1;
			dfs(g,v.val,u);
			size[u]+=size[v.val];
		}
	}
}

inline ll lca(ll u,ll v)
{
	if(lvl[v]>lvl[u]) swap(u,v);
	for(int i=LN-1;i>=0;i--)
		if(lvl[u]-(1<<i)>=lvl[v])
			u=p[u][i];
	if(u==v) return u;
	for(int i=LN-1;i>=0;i--)
	if(p[u][i]!=p[v][i])
		u=p[u][i],v=p[v][i];
	return p[u][0];
}

ll chainNo,ptr;
// vll chaindet[N];
void hld(vector<edge>g[],ll u,ll par,ll cost)
{
	if(chead[chainNo]==0)
		chead[chainNo]=u;

	// chaindet[chainNo].pb(u);
	cindex[u]=chainNo;
	posInBase[u]=ptr;
	basearray[ptr++]=cost;

	ll sc=-1,newcost;
	for(auto&v:g[u])
	{
		if((sc==-1||size[sc]<size[v.val])&&v.val!=par)
			sc=v.val,newcost=v.c;
	}
	if(sc!=-1)
		hld(g,sc,u,newcost);

	for(auto&v:g[u])
	{
		if(v.val!=sc&&v.val!=par)
			chainNo++,hld(g,v.val,u,v.c);
	}
}

ll query_up(ll u,ll v)
{
	if(u==v)return 0;
	ll uchain, vchain=cindex[v],ans=-1,ret;
	while(1)
	{
		uchain=cindex[u];
		if(uchain==vchain)
		{
			if(u==v)break;
			ret=query_tree(1,posInBase[v]+1,posInBase[u]);
			ans=max(ret,ans);
			break;
		}
		ret=query_tree(1,posInBase[chead[uchain]],posInBase[u]);
		ans=max(ans,ret);
		u=chead[uchain];
		
		u=p[u][0];
		
		
	}
	return ans;
}

void query(ll u, ll v) {			
	ll LCA = lca(u, v);		
	ll ans = query_up(u, LCA); // One part of path	
	ll temp = query_up(v, LCA); 
	if(temp > ans) ans = temp; 
	printf("%d\n", ans);
}

int main()
{
	ll t;
	t=rll
	while(t--)
	{
		ptr =1;
		clr(basearray);
		ll u,v,c,n,m,i; n = rll m=n-1;
		vector< edge > g[n+1];
		vector<pll > edgeIndex;
		edgeIndex.pb(mp(0,0));

		edge e;
		FOR(i,0,m-1)
		{
			u=rll v=rll c=rll
			e.val=v; e.c=c;
			edgeIndex.pb(mp(u,v));
			g[u].pb(e);e.val=u;
			g[v].pb(e);
		}	
		
		dfs(g,1,-1);
		hld(g,1,-1,-1);
		init(1,1,n);
		// cout<<endl<<"basearray:";
		FOR(i,1,ptr-1)
		{
			increment(1,i,i,basearray[i]);
			// cout<<basearray[i]<<" ";
		}
		// cout<<endl;
		// FOR(i,0,chainNo)
		// {
		// 	cout<<"\nchain "<<i<<":";
		// 	for(auto&k:chaindet[i])
		// 		cout<<"("<<k<<","<<cindex[k]<<") ";
		// }

		string s;
		while(1)
		{
			cin>>s;
			if(s=="CHANGE")
			{
				
			}
			if(s=="QUERY")
			{
				u=rll v=rll
				query(u,v);
			}
			if(s=="TEST")
			{
				
				ll ii,jj;
				FOR(ii,1,n)
				FOR(jj,1,n)
				cout<<ii<<" "<<jj<<": ",query(ii,jj);
			}
			if(s=="DONE")
				break;
		}
	}
	return 0;
}