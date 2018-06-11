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

const int N = (int) 1e5+5;

int n,m,f,s,t,a,b;
int A[N];
bool visited[N];
vector<int> g[N];
unordered_map<int,string>numtoname;
unordered_map<string,int>nametonum;

vector<int>ff,ss,tt;
vector<string>members;
void dfs(int u)
{
    visited[u] = true;
    members.pb(numtoname[u]);
    for(auto v: g[u])
    {
        if(!visited[v])
        {
            dfs(v);
        } 
    }
}

void init(vector<int>&p,vector<int>&rank,int n)
{
    p.resize(n+1);
    rank.resize(n+1);
    ff.resize(n+1);
    ss.resize(n+1);
    tt.resize(n+1);
    for(int i = 1; i <= n; i++)
    {
        p[i] = i;
        rank[i] = 1;
        ff[i] = ss[i] = tt[i] = 0;
        switch(A[i])
        {
            case 1: ff[i] = 1;
                break;
            case 2: ss[i] = 1;
                break;
            case 3: tt[i] = 1;
                break;
        }
    }
}

int find(vector<int>&p,int u)
{
    int root = u;
    while(p[root] != root)
        root = p[root];
    while(u != root)
    {
        auto temp = u;
        u = p[u];
        p[temp] = root;
    }
    return root;
}
void merge_set(vector<int>&p,vector<int>&rank,int u,int v)
{
    auto uu = u;
    auto vv = v;
    u = find(p,u);
    v = find(p,v);
    if((rank[u]+rank[v]>b) || (ff[u] + ff[v] > f) || (ss[u]+ss[v] > s) || (tt[u]+tt[v] > t)) return;

    if(rank[v] < rank[u])
    {
        rank[u] += rank[v];
        ff[u] += ff[v];
        ss[u] += ss[v];
        tt[u] += tt[v];
        p[v] = u;
    } else {
        rank[v] += rank[u];
        ff[v] += ff[u];
        ss[v] += ss[u];
        tt[v] += tt[u];
        p[u] = v;
    }

    g[uu].pb(vv);
    g[vv].pb(uu);
}


int main()
{
    n = rll m = rll a = rll b = rll f = rll s = rll t = rll;
    string name,u,v;
    int grade;
    
    FOR(i,1,n)
    {
        cin>>name>>grade;
        numtoname[i] = name;
        nametonum[name] = i;
        A[i] = grade;
    }
    
    vector<int>p,rank;
    init(p,rank,n);
    
    FOR(i,1,m)
    {
        cin>>u>>v;
        auto uu = nametonum[u];
        auto vv = nametonum[v];
        if(find(p,uu)!=find(p,vv))
        {
            merge_set(p,rank,uu,vv);
        }
    }
    
    int largest = -1;
    
    FOR(i,1,n)
    {
        auto pp = find(p,i);
        if(!visited[pp] && rank[pp] >= a)
        {
            if(rank[pp] > largest)
            {
                largest = rank[pp];
            }
        }   
    }
    
    if(largest == -1) return !printf("no groups");
    
    vector<int>answers;
    clr(visited);
    FOR(i,1,n)
    {
        if(visited[i]) continue;
        auto pp = find(p,i);
        if(!visited[pp] && rank[pp] == largest)
            dfs(pp);
    }
    
    
    sort(all(members));
    
    for(auto member:members)
        cout<<member<<endl;
    
   return 0;
}
