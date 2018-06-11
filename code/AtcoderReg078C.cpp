#include<bits/stdc++.h>
#define FOR(i,a,b) for(i=a;i<=b;i++)
#define RFOR(i,a,b) for(i=a;i>=b;i++)
typedef long long ll;
using namespace std;
int main()
{
ll i,n;
cin>>n;
ll a[n],p[n];
FOR(i,0,n-1)
cin>>a[i];
p[0]=a[0];
FOR(i,1,n-1)
p[i]=p[i-1]+a[i];
ll tt=p[n-1];
 
ll mini=INT_MAX;
FOR(i,0,n-2)
mini=min(abs(2*p[i]-tt),mini);
cout<<mini;
return 0;
}