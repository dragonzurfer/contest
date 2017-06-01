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
	ll n,i;cin>>n;
	string s="aa";
	if(n==1)
		cout<<s[0];
	else if(n==2)
		cout<<s;
	else
	{
		FOR2(i,2,n-1)
		if(s[i-2]=='a')
			s.pb('b');
		else if(s[i-2]=='b')
			s.pb('a');
	cout<<s;
	}
	return 0;
}
