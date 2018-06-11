#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define vll vector<ll>
#define first F
#define second S
#define pll pair<ll,ll>
#define FOR(i,a,b) for(i=a;i<=b;i++)
#define endl '\n'
#define clr(a) memset(a,0,sizeof(a))
typedef long long ll;
set<ll>depends,terminal;
vll ans;
void dfs(list<ll>graph[],bool visited[],ll v,vll d)
{
	depends.insert(v);
	if(d[v]==0)
		terminal.insert(v);
	visited[v]=true;
	for(auto&u:graph[v])
		if(!visited[u])
			dfs(graph,visited,u,d);
}

void topsort(list<ll>r_graph[],vll d)
{
	while(!terminal.empty())
	{
		ll least=*terminal.begin();
		terminal.erase(least);
		ans.pb(least);
		for(auto&adj:r_graph[least])
		{
			d[adj]-=1;
			if(d[adj]==0&&depends.count(adj))
				terminal.insert(adj);
		}
	}
}
int main()
{
	ll q;
	cin>>q;
	while(q--)
	{
		terminal.clear();
		depends.clear();
		ans.clear();
		ll n,m,t,v,i,j;
		cin>>n>>m;
		list<ll> graph[n+1];
		list<ll> r_graph[n+1];
		
		vll d(n+1,0);
		FOR(i,0,n-1)
		{
			cin>>d[i+1];
			FOR(j,0,d[i+1]-1)
			{
				cin>>v;
				graph[i+1].pb(v);
				r_graph[v].pb(i+1);
			}
		}
			
	
			set<ll>prgms;
			bool visited[n+1];
			memset(visited,false,sizeof(visited));
			FOR(i,0,m-1)
			{
				cin>>t;
				dfs(graph,visited,t,d);
			}
			
			topsort(r_graph,d);
			
			
			cout<<ans.size()<<endl;
			for(auto&k:ans)
				 cout<<k<<" ";
				cout<<endl;	
			
	}
	return 0;
}