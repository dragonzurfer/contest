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

const int N = (int)3e5+10;

int n,x,y,u,v;
gg g[N];

int main()
{
    cin>>n>>x>>y;
    FOR(i,1,n-1) {
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    function<int(int,int,int)> dfs = [&](int u, int k, int p = -1) {
        ll ans = 1;
        for(auto v : g[u])
        {
            if(v == p || v == k) continue;
            ans += dfs(v, k, u);
        }
        return ans;
    };
    ll nx = n - dfs(y,x,-1);
    ll ny = n - dfs(x,y,-1);
    ll ans = nx*(nx-1) + ny*(ny-1) + nx*ny + ((nx + ny)*2 + (n-nx-ny-1))*(n-nx-ny);
    cout<<ans;
    return 0;
}