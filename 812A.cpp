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
	ll l1,l2,l3,l4,s1,s2,s3,s4,r1,r2,r3,r4,p1,p2,p3,p4;
	cin>>l1>>s1>>r1>>p1;
	cin>>l2>>s2>>r2>>p2;
	cin>>l3>>s3>>r3>>p3;
	cin>>l4>>s4>>r4>>p4;
	if((l1&&p4)||(l2&&p1)||(l3&&p2)||(l4&&p1)||
	   (s1&&p3)||(s2&&p4)||(s3&&p1)||(s4&&p2)||
	   (r1&&p2)||(r2&&p3)||(r3&&p4)||(r4&&p1)
		)
		cout<<"YES";
	else
		cout<<"NO";
	return 0;
}