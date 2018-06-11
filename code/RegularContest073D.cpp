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
#define FOR1(i,a) for(i=0;i<=a;i++)
#define FOR2(i,a,b) for(i=a;i<=b;i++)
#define endl '\n'
#define clr(a) memset(a,0,sizeof(a))
#define all(x) x.begin(),x.end()
#define rll read_ll();
#ifndef ONLINE_JUDGE
#define gc getchar
#define pc putchar
#else
#define gc getchar_unlocked
#define pc putchar_unlocked
#endif
typedef long long ll;
ll read_ll(){char c=gc();while((c<'0'||c>'9')&&c!='-')c=gc();ll ret=0;int neg=0;if(c=='-')neg=1,c=gc();while(c>='0'&&c<='9'){ret=10*ret+c-48;c=gc();}return neg?-ret:ret;}

int main()
{
	ll n,W;
	cin>>n>>W;
	vll w(n+1),val(n+1);
	ll i,j;
	FOR2(i,1,n)
	cin>>w[i]>>val[i];
	vector< vector<ll> > dp(n+1, vector<ll>(W+1,0));
	
	FOR2(i,1,n)
	{
		FOR2(j,1,W)
		{
			dp[i][j]=max(dp[i-1][j],((j>=w[i])?dp[i-1][j-w[i]]+val[i]:0));
		}
	}

	cout<<dp[n][W];
	return 0;
}