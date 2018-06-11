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

const int N = (int) 1e5 + 10;

int n,m,A[N];
vector<int> g[N];
bool visited[N];
set<int>visitedSet,values;

void dfs(int u)
{
    visitedSet.insert(u);
    values.insert(A[u]);
    visited[u] = true;
    for(auto v : g[u])
    {
        if(visited[v]) continue;
        dfs(v);
    }
}

int main()
{
    clr(A);
    clr(g);
    clr(visited);
    cin>>n>>m;
    int u,v;
    for(int i = 1; i <= n; i++)
        cin>>A[i];
    for(int i = 0; i < m; i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans = 0;
    for(int i = 1; i < n; i++)
    {
        if(!visited[i])
        {
            dfs(i);
            for(auto ele : visitedSet)
            {
                if(values.count(ele))
                    ans++;
            }
            visitedSet.clear();
            values.clear();
        }
    }
    
    cout<<ans;
    
    return 0;
}











