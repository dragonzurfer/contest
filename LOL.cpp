#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define vll vector<ll>
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
	ll t;cin>>t;
	while(t--){
	ll n,i,j,k;

	string s;cin>>s;n=s.length();
	vector<ll>prefix(n,0),suffix(n,0);
	
	if(s[0]=='L')
		prefix[0]=1;

	FOR2(i,1,n-1)
	if(s[i]=='L')
		prefix[i]=prefix[i-1]+1;
	else
		prefix[i]=prefix[i-1];

	if(s[n-1]=='L')
		suffix[n-1]=1;

	for(i=n-2;i>=0;i--)
	if(s[i]=='L')
		suffix[i]=suffix[i+1]+1;
	else
		suffix[i]=suffix[i+1];

	ll cnt=0;
	FOR2(i,1,n-2)
	if(s[i]=='O')
		cnt+=(prefix[i-1]*suffix[i+1]);

	cout<<cnt<<endl;
}
	return 0;
}