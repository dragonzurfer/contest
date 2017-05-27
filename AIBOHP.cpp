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

int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		string s,rev;
		cin>>s;
		rev=s;
		ll n=s.length();
		ll m=n,i,j;
		reverse(rev.begin(),rev.end());
		ll dp[n+1][m+1];clr(dp);

		FOR2(i,1,n)
		{
			FOR2(j,1,n)
			{
				if(s[i-1]==rev[j-1])
					dp[i][j]=(1+dp[i-1][j-1]);
				else
					dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
		cout<<n-dp[n][m]<<endl;

	}
	return 0;
}
