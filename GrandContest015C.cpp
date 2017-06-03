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
auto& in = std::cin;
auto& out = std::cout;

int main()
{
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);
	ll n,m,q,i,j,p;
	in>>n>>m>>q;
	vector<vector<char> > g(n);
	FOR1(i,n-1)
	{
		g[i].resize(m);
		FOR1(j,m-1)
		in>>g[i][j];
	}
	G dp(n);dp[0].resize(m);
	dp[0][0]=((g[0][0]=='1')?1:0);

	FOR2(i,1,n-1)
	{
		dp[i].resize(m);
		dp[i][0]=dp[i-1][0];
		if(g[i][0]=='1')
		dp[i][0]+=1;
	}
	FOR2(j,1,n-1)
	{
		dp[0][j]=dp[0][j-1];
		if(g[0][j]=='1')
		dp[0][j]+=1;
	}

	FOR2(i,1,n-1)
	{
		FOR2(j,1,m-1)
		{	
			dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
			if(g[i][j]=='1')
				dp[i][j]+=1;
		}		
	}
	FOR1(i,n-1)
	{
		FOR1(j,m-1)
		out<<dp[i][j]<<" ";out<<endl;
	}
	
	ll x1,x2,y1,y2,max,leftsum,topsum,centersum;
	cout<<"HI:";
	while(q--)
	{
	in>>x1>>y1>>x2>>y2;

	max=dp[x2][y2];
	leftsum=((y1>0)?dp[x2][y1-1]:0);
	// cout<<"\nLEFTSUM:"<<leftsum;cin>>p;
	topsum=((x1>0)?dp[x1-1][y2]:0);
	// cout<<"\ntopsum:"<<topsum;cin>>p;
	centersum=((x1>0&&y1>0)?dp[x1-1][y1-1]:0);
	// cout<<"\ncentersum:"<<centersum;cin>>p;
	cout<<"\nanswer:"<<max-(leftsum+topsum-centersum);
}
	return 0;
}