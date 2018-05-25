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
#define RFOR(i,a,b) for(int i=a;i>=b;i--)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define endl '\n'
#define clr(a) memset(a,0,sizeof(a))
#define all(x) x.begin(),x.end()
#define rll read_ll();
#define gc getchar
#define pc putchar
#define deb2(a,b,c,d) cout<<a<<":"<<b<<" "<<c<<":"<<d<<endl;
typedef long long ll;
template<class T> inline T lcm(T a,T b){
        return a/gcd(a,b)*b;
}
template<typename T>
void printer(T first) {
    cout << first << "\n";
}
template<typename T, typename... Args>
void printer(T first, Args... args) {
    cout << first << " ";
    printer(args...);
}


ll read_ll(){char c=gc();while((c<'0'||c>'9')&&c!='-')c=gc();ll ret=0;int neg=0;if(c=='-')neg=1,c=gc();while(c>='0'&&c<='9'){ret=10*ret+c-48;c=gc();}return neg?-ret:ret;}

const int N = 5*(int)1e4+5;

int main()
{
    int n,r1,r2,u,v;
    scanf("%d %d %d",&n,&r1,&r2);
    vector<int>g[n+1],ans(n+1,0);
    FOR(i,0,n-2)
    {
        scanf("%d",&u);
        v = i+1;
        if(i+1>=r1)
            v+=1;
        // cout<<u<<" "<<v<<endl;
        g[u].pb(v);
        g[v].pb(u);
    }
    
    function<void(int,int)> dfs = [&](int u,int p = -1){
        // cout<<u<<":"<<p<<endl;
        ans[u] = p;
        for(auto v:g[u])
        {
            if(v==p) continue;
            dfs(v,u);
        }
    };
    dfs(r2,-1);
    
    for(int i = 1; i <= n; i++)
        if(ans[i]>0)cout<<ans[i]<<" ";//cout<<endl;
    
    return 0;
}
