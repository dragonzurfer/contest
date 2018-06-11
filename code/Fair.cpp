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

const int INF =(ll)(1e8);
const int K = 101;
struct node{
  vector<int>closest;
  int v;
    node(int val):v(val){}
};

const int N = (int)1e5+5;
int n,m,k,s;

vector<int>g[N];
vector<int>A(N);
vector<vector<int> > nodeWhoHave(K,vector<int>(0));
int closest[N][K];

int main()
{
   cin>>n>>m>>k>>s;
   FOR(i,1,n)
   {
       cin>>A[i];
       nodeWhoHave[A[i]].pb(i);
   }
    int u,v;
    clr(closest);
    
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= k; j++)
        closest[i][j] = -1;
    }
    FOR(i,1,m)
    {
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    
    for(int kk = 1; kk <= k; kk++)
    {
        queue<int>q;
        for(auto u : nodeWhoHave[kk])
        {
            closest[u][kk] = 0;
            q.push(u);
        }
        while(!q.empty())
        {
            auto front = q.front(); q.pop();
            for(auto v : g[front])
            {
                if(closest[v][kk] != -1) continue;
                closest[v][kk] = closest[front][kk] + 1;
                q.push(v);
            }
        }
    }
    vector<int>ans(n+1);
    FOR(i,1,n)
    {
        
        long long sum = 0;
        vector<int>soln(k);
        FOR(j,1,k)
        {
            soln[j-1] = closest[i][j];
        }
        sort(all(soln));
        FOR(j,0,s-1) sum += soln[j];
        ans[i] = sum;
    }
    
    FOR(i,1,n) cout<<ans[i]<<" ";
    
   return 0;
}
