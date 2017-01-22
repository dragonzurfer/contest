#include <bits/stdc++.h>
#define k 8
using namespace std;
typedef long long ll;

int cnv (char s)
{
	return int(s-'0');
}
int main()
{
	ll n;
	cin>>n;
	ll cnt=1e9+7;
	char s[n+5];
	cin>>s;
	ll dp[2][k];
	for(ll i=0;i<2;i++) {
		for(ll j=0;j<k;j++)
			dp[i][j] = 0;
	}
	dp[0][0]=1;

	for(ll i=0;i<n;i++)
	{
		for(ll r=0;r<k;r++)
		{
			dp[1][(r*10+cnv(s[i]))%k]=(dp[1][(r*10+cnv(s[i]))%k]%cnt+dp[0][r]%cnt)%cnt;
			dp[1][r]=(dp[1][r]%cnt+dp[0][r]%cnt)%cnt;
		}
		for(ll r=0;r<k;r++)
			dp[0][r]=dp[1][r],dp[1][r]=0;
	}
	cout<<dp[0][0] - 1;
	return 0;
}