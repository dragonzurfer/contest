    #include <bits/stdc++.h>
    using namespace std;
    #define mp make_pair
    #define pb push_back
    #define lb lower_bound
    #define up upper_bound
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
    #define rll read_ll();
    #ifndef ONLINE_JUDGE
    #define gc getchar
    #define pc putchar
    #else
    #define gc getchar_unlocked
    #define pc putchar_unlocked
    #endif
    typedef long long ll;
    ll read_ll(){char c=gc();while((c<'0'||c>'9')&&c!='-')c=gc();ll ret=0;int neg=0;if(c=='-')neg=1,c=gc();while(c>='0'&&c<='9'){ret=10*ret+c-48;c=gc();}return neg?-ret:ret;}
     
    int main()
    {
    	ll n,t,i;
    	n=rll t=rll
    	vll a(n+1);
    	FOR1(i,n-1)
    	{
    		cin>>a[i];
    	}
    	a[i]=1000000000000;
    	// ll endtime=a[0]+t;
    	ll runtime=0,endtime=0;
    	// bool flag;
    	FOR2(i,0,n-1)
    	{
    		runtime+=min(t,a[i+1]-a[i]);
    	}
    	// cout<<runtime<<" ";
    	// cout<<endtime;
    	cout<<runtime;
    	
    	return 0;
    }