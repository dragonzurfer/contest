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

	G V(n),EH(n),EV(n);

	V[0].resize(m);EH[0].resize(m);EV[0].resize(m);
	V[0][0]=((g[0][0]=='1')?1:0);
	EV[0][0]=0;
	EH[0][0]=0;
	FOR2(i,1,n-1)
	{
		V[i].resize(m);EH[i].resize(m);EV[i].resize(m);

		V[i][0]=V[i-1][0];
		EV[i][0]=EV[i-1][0];

		if(g[i][0]=='1')
		{
			V[i][0]+=1;
			if(g[i-1][0]=='1')
				EV[i][0]=EV[i-1][0]+1;
		}
	}

	FOR2(j,1,m-1)
	{
		V[0][j]=V[0][j-1];
		EH[0][j]=EH[0][j-1];
		if(g[0][j]=='1')
		{
			V[0][j]+=1;
			if(g[0][j-1]=='1')
				EH[0][j]=EH[0][j-1]+1;
		}
	}

	FOR2(i,1,n-1)
	{
		FOR2(j,1,m-1)
		{	
			// Subtract the common region only when both top and left are recounting
			V[i][j]=V[i-1][j]+V[i][j-1]-((V[i-1][j]==0||V[i][j-1]==0)?0:V[i-1][j-1]);
			EH[i][j]=EH[i-1][j]+EH[i][j-1]-((EH[i-1][j]==0||EH[i][j-1]==0)?0:EH[i-1][j-1]);
			EV[i][j]=EV[i-1][j]+EV[i][j-1]-((EV[i-1][j]==0||EV[i][j-1]==0)?0:EV[i-1][j-1]);
			if(g[i][j]=='1')
			{
				V[i][j]+=1;
				if(g[i-1][j]=='1')
					EV[i][j]+=1;
				if(g[i][j-1]=='1')
					EH[i][j]+=1;
			}
		}		
	}
	
	ll x1,x2,y1,y2,max,leftsum,topsum,centersum,countV,countE;
	while(q--)
	{
		in>>x1>>y1>>x2>>y2;
		--x1,--x2,--y1,--y2;

		max=V[x2][y2];
		leftsum=((y1>0)?V[x2][y1-1]:0);
		topsum=((x1>0)?V[x1-1][y2]:0);
		centersum=((x1>0&&y1>0)?V[x1-1][y1-1]:0);

		countV=max-(leftsum+topsum-centersum);

		max=EH[x2][y2]+EV[x2][y2];
		leftsum=EH[x2][y1]+((y1>0)?EV[x2][y1-1]:0);
		topsum=EV[x1][y2]+((x1>0)?EH[x1-1][y2]:0);
		centersum=((x1>0)?EH[x1-1][y1]:0)+((y1>0)?EV[x1][y1-1]:0);

		countE=max-(leftsum+topsum-centersum);
		// number of trees=Vertices in forest -Edges in forest
		cout<<countV-countE<<endl;
	}
	return 0;
}