#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define vl vector<ll>
#define first F
#define second S
#define pll pair<ll,ll>
#define FOR(i,a,b) for(i=a;i<=b;i++)
#define endl '\n'
#define clr(a) memset(a,0,sizeof(a))
typedef long long ll;


int main()
{
	ll n,k,i,j;
	cin>>n>>k;
	ll bag[n];

	FOR(i,0,n-1)
	cin>>bag[i];

	sort(bag,bag+n);
	
	
	ll sum=bag[0]+bag[1],fairness=bag[1]-bag[0];
	FOR(i,2,k-1)
	{
		fairness=fairness+abs(sum-i*bag[i]);
		sum+=bag[i];
	}
	
	ll oldsum=sum,newsum=0,newfairness,oldfairness=fairness;
	
	for(i=k;i<=n-1;i++)
	{
		sum=sum-bag[i-k];
		newfairness=oldfairness-2*(sum)+(k-1)*bag[i-k]+(k-1)*bag[i];
		sum=sum+bag[i];
		fairness=min(fairness,newfairness);
		
		oldfairness=newfairness;
	}

	cout<<fairness;
	return 0;
}





