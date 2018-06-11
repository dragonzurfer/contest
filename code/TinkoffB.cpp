#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
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

bool visited[1005][1005][5][4];
ll n,m;
int starti,startj,ti,tj;
vector<vector<char> >g(1005);
int adj[]={0,1,2,3};

bool can_go(char dir,ll si,ll sj)
{
	if(dir==0&&(sj-1)>=0)
		return true;
	if(dir==1&&(sj+1)<m)
		return true;
	if(dir==2&&(si-1)>=0)
		return true;
	if(dir==3&&(si+1)<n)
		return true;
	return false;
}

ll bfs(ll si,ll sj,int dir,ll turns)
{
	queue<pair<pll,pair<char,ll> > >q;
	ll nturns;

	q.push(mp(mp(si,sj),mp(dir,turns)));

	while(!q.empty())
	{
		pair<pll,pair<char,ll> > s=q.front();q.pop();
		si=s.F.F,sj=s.F.S;
		turns=s.S.S,dir=s.S.F;
		if(g[si][sj]=='T')
			if(turns<=2&&turns>=0)
				{cout<<"YES";exit(0);}

		for(auto&newdir:adj)
		{
			if(newdir!=dir)
				nturns=turns+1;
			else 
				nturns=turns;
			
			if(dir==4)
				nturns=turns;

			if(nturns<=2&&can_go(newdir,si,sj))
			{
				if(newdir==0&&g[si][sj-1]!='*'&&!visited[si][sj-1][newdir][nturns])
					visited[si][sj-1][newdir][nturns]=true,q.push(mp(mp(si,sj-1),mp(newdir,nturns)));
					
				if(newdir==1&&g[si][sj+1]!='*'&&!visited[si][sj+1][newdir][nturns])
					visited[si][sj+1][newdir][nturns]=true,q.push(mp(mp(si,sj+1),mp(newdir,nturns)));
					
				if(newdir==2&&g[si-1][sj]!='*'&&!visited[si-1][sj][newdir][nturns])
					visited[si-1][sj][newdir][nturns]=true,q.push(mp(mp(si-1,sj),mp(newdir,nturns)));
					
				if(newdir==3&&g[si+1][sj]!='*'&&!visited[si+1][sj][newdir][nturns])
					visited[si+1][sj][newdir][nturns]=true,q.push(mp(mp(si+1,sj),mp(newdir,nturns)));	
			}
		}
	}
}

int main()
{
	ll i,j;
	cin>>n>>m;
	char s;
	FOR1(i,n-1)
	FOR1(j,m-1)
	{
		cin>>s;
		g[i].pb(s);
		if(s=='S')
			starti=i,startj=j;
		else if(s=='T')
			ti=i,tj=j;
	}
	visited[starti][startj][4][0]=true;
	bfs(starti,startj,4,0);
	cout<<"NO";
	return 0;
}