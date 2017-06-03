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
	ll i,count=0;
	string s;
	cin>>s;
	if(s[s.length()-1]=='1')
		count=1;
	for(i=s.length()-2;i>=0;i--)
	{
		if(s[i]!=s[i+1])
			count+=1;
	}
	cout<<count;
	return 0;
}