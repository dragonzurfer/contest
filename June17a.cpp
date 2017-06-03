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
	ll t,i;cin>>t;
	ll pp,p,c;
	while(t--)
	{
		ll n,inc;cin>>n;
		pp=p=-1;
		if(n==1)
			cout<<"1 ";
		else if(n==2)
			cout<<"1 2";
		else{
			cout<<"1 2 4 ";
			c=4;
			inc=3;
			FOR2(i,2,n-2)
			{
				c=3+c;
				cout<<c<<" ";
			}

		}
		cout<<endl;
	}
	return 0;
}