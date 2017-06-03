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
#ifndef ONLINE_JUDGE
#define gc getchar
#define pc putchar
#else
#define gc getchar_unlocked
#define pc putchar_unlocked
#endif

    typedef long long ll;
int read_int() {
    char c = gc();
    while((c < '0' || c > '9') && c != '-') c = gc();
    int ret = 0, neg = 0;
    if (c == '-') neg = 1, c = gc();
    while(c >= '0' && c <= '9') {
        ret = 10 * ret + c - 48;
        c = gc();
    }
    return neg ? -ret : ret;
}

ll read_ll() {
    char c = gc();
    while((c < '0' || c > '9') && c != '-') c = gc();
    ll ret = 0;
    int neg = 0;
    if (c == '-') neg = 1, c = gc();
    while(c >= '0' && c <= '9') {
        ret = 10 * ret + c - 48;
        c = gc();
    }
    return neg ? -ret : ret;
}
     
    ll mod=1000000007;
    int main()
    {
    	ll t,i;cin>>t;
    	while(t--)
    	{
    		ll na,nb,nc;
    		na=read_ll(),nb=read_ll(),nc=read_ll();
    		vll A(na),B(nb),C(nc);
    		FOR1(i,na-1)
    		A[i]=read_ll();
    		FOR1(i,nb-1)
    		B[i]=read_ll();
    		FOR1(i,nc-1)
    		C[i]=read_ll();
     
    		sort(all(A));sort(all(B));sort(all(C));
     
     
    		ll Y,xcount,zcount,X,Z,ans=0;
    		ll ai=-1,ci=-1;
    		X=0,Z=0;
    		bool flag1=false,flag2=false;
    		FOR1(i,nb-1)
    		{
    			Y=B[i];

    			if(!flag1)
    			while(ai+1<na&&A[ai+1]<=Y)
    				{++ai,X=(X+A[ai])%mod;if(ai==na-1)flag1=true;}

    			if(!flag2)
    			while(ci+1<nc&&C[ci+1]<=Y)
    				{++ci,Z=(Z+C[ci])%mod;if(ci==nc-1)flag2=true;}

    			xcount=ai+1;
    			zcount=ci+1;
    			
    			if(xcount!=0&&zcount!=0)
    			ans=(ans%mod+(( (X+(xcount%mod*Y%mod)%mod)%mod * (Z+(zcount%mod*Y%mod)%mod)%mod ) %mod)%mod )%mod;
    		}
    	
    		cout<<ans<<endl;
    	}
    	return 0;
    } 