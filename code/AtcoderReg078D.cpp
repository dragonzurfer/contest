#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
#define clr(a) memset(a,0,sizeof(a))
using namespace std;
typedef long long ll;
const int N=1e5+3;
int p[N],dist[N];
vector<int> g[N];
 
void dfs(int u,int pa,int f)
{
  p[u]=pa;
  for(auto&v:g[u])
    if(v!=pa)
    dist[v]=dist[u]+1,dfs(v,u,f);
  	else if(v!=pa&&v==f)
    {
      dist[v]=dist[u]+1;
      p[v]=u;
      break;
    }
}
int cnt;
void dfs2(int u,int pa)
{
  cnt++;
  for(auto&v:g[u])
    if(v!=pa)
    dfs2(v,u);
}
 
int main()
{
	int i,n,u,v;
  	cin>>n;
    FOR(i,1,n-1)
    {
      cin>>u>>v;
      g[u].pb(v);
      g[v].pb(u);
    }
  dfs(n,n,1);
  i=1;
  int flag=0;
  vector<int>a;
  while(p[i]!=i)
  {
  	flag=1;
  	a.pb(i);
  	i=p[i];
  }
  if(flag)
  a.pb(i);

  int slow,nn=a.size(),prev;
  
  if(a.size()%2==0)
  slow=a[nn/2],prev=((nn/2-1>-1)?a[nn/2-1]:-1);
  else
  slow=a[nn/2+1],prev=a[nn/2];

  dfs2(slow,prev);

  if(cnt>=(n-cnt))
    cout<<"Snuke";
  else cout<<"Fennec";
    
}