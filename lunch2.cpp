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
typedef int64_t ll;
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
const ll LN = 17;
const ll N=1e5 + 42;
vector<ll> g[N];
ll ans[N],a[N],lvl[N];
ll p[N][LN],minxtop[N][LN];

void dfs(ll u)
{
    ll par=u;
    //find the parent whose node val is <= a[u]
    for(ll i=LN-1;i>=0;i--)
        if(minxtop[par][i]>=a[u])
            par=p[par][i];
    
    par=p[par][0];//assign it to par
    ans[u]=ans[par]+(lvl[u]-lvl[par])*a[u];//dp equation
    
    for(auto&v:g[u])
    {
        p[v][0]=u;
        minxtop[v][0]=a[u];
        for(ll i=1;i<LN;i++)//update
        {
            p[v][i]=p[p[v][i-1]][i-1];
            minxtop[v][i]=min(minxtop[minxtop[v][i-1]][i-1],minxtop[v][i-1]);
        }
        lvl[v]=lvl[u]+1;
        dfs(v);
    }

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,t,i;
    n=read_ll();

    FOR2(i,2,n)
    {
        t=read_ll();
        g[t].pb(i);
    }

    lvl[0]=0;
    g[0]={1};
    a[0]=0;

    FOR2(i,1,n)
    a[i]=read_ll();  
    dfs(0);

    FOR2(i,1,n)
        cout<<ans[i]<<" ";
    
    return 0;
}