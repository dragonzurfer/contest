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

ll mod=1000000007;

int main()
{
	string s;
	cin>>s;
	ll curr,prev,sum,prevsum,n,i;
	curr=prevsum=prev=0;
	
	n=s.length();
	int currnum=(s[0]-'0');//.c_str());
	curr=(ll)currnum;
	prevsum	= curr;
	sum=curr;
	FOR2(i,1,n-1)
	{
		currnum=(int)(s[i]-'0');
		prevsum= ((prevsum*10) + ((i+1)*currnum))%mod;
		sum= (sum%mod+prevsum%mod)%mod;
	}
	cout<<sum;
	
	return 0;
}