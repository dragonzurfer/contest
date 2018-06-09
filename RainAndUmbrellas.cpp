#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define up upper_bound
#define vll vector<ll>
#define G vector<vll >
#define gg vector<int>
#define F first
#define S second
#define pll pair<ll,ll>
#define pii pair<int,int>
#define RFOR(i,a,b) for(int i=a;i>=b;i--)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define endl '\n'
#define clr(a) memset(a,0,sizeof(a))
#define all(x) x.begin(),x.end()
#define rll read_ll();
#define gc getchar
#define pc putchar
typedef long long ll;
template<class T> inline T lcm(T a,T b){
        return a/gcd(a,b)*b;
}
template<typename T>
void debug(T first) {
    cout << first << "\n";
}
template<typename T, typename... Args>
void debug(T first, Args... args) {
    cout << first << " ";
    debug(args...);
}


ll read_ll(){char c=gc();while((c<'0'||c>'9')&&c!='-')c=gc();ll ret=0;int neg=0;if(c=='-')neg=1,c=gc();while(c>='0'&&c<='9'){ret=10*ret+c-48;c=gc();}return neg?-ret:ret;}
const int INF = INT_MAX;
int main()
{
    int a, n, m;
    cin>> a >> n >> m;
    ll rain[a+2], dp[a+2], umb[a+2];
    clr(rain); clr(umb);
    FOR(i,1,n)
    {
        int l, r; cin>> l >> r;
        FOR(j,l,r-1)
            rain[j] = 1;
    }
    FOR(i,1,m)
    {
        ll loc, w;
        cin>> loc >> w;
        if(umb[loc] == 0)
        umb[loc] = w;
        else umb[loc] = min(umb[loc],w);
    }
    
    clr(dp);
    FOR(i,1,a+1)
    {
        dp[i] = INF;
        if(rain[i-1])
        {
            FOR(j,0,i-1)
            {
                if(umb[j] == 0) continue;
                dp[i] = min(dp[j]+(i-j)*umb[j],dp[i]);
            }
            
        } else {
            dp[i]  = dp[i-1];
        }
        
    }
    // FOR(i,0,a) cout<<dp[i]<<" ";cout<<endl;
    // FOR(i,0,a) cout<<rain[i]<<" ";cout<<endl;
    ll ans = ((dp[a] == INF)?-1:dp[a]);
    cout<<ans<<endl;
   return 0;
}
