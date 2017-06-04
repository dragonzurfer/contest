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
	ll n;cin>>n;
	ll csum=0,dsum=0;
	ll t;
	ll smt=INT_MAX;
	while(n--)
	{
		cin>>t;
		if(t%10&&smt>t)
			smt=t;
		dsum+=t;
	}
	if(!(dsum%10)&&smt!=INT_MAX)
	    cout<<dsum-smt<<endl;
	else if(dsum%10)
		cout<<dsum;
	else
		cout<<'0';
	return 0;
}