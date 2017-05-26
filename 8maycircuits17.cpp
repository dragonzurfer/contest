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
	ll t,temp,N,i;cin>>t;
	while(t--)
	{
		cin>>N;
		vll A(N),lincr(N),rincr(N),ldecr(N),rdecr(N);
		FOR1(i,N-1)
		cin>>temp,A[i]=temp,lincr[i]=ldecr[i]=rincr[i]=rdecr[i]=i;
		FOR2(i,1,N-1)
		{
			if(A[i]<=A[i-1])
				lincr[i]=lincr[i-1];
			if(A[i]>=A[i-1])
				ldecr[i]=ldecr[i-1];
		}
		for(i=N-2;i>=0;i--)
		{
			if(A[i]<=A[i+1])
				rincr[i]=rincr[i+1];
			if(A[i]>=A[i+1])
				rdecr[i]=rdecr[i+1];
		}
		ll minl,maxr,omax=-1;
		FOR1(i,N-1)
		{
			minl=min(ldecr[i],rdecr[i]);
			maxr=max(rdecr[i],rincr[i]);
			omax=max(omax,max(abs(A[i]-A[minl]),abs(A[maxr]-A[i])));
		}
		cout<<omax<<endl;
	}
	return 0;
}