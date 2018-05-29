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
const int LN = 19;
const int N = 2e5+5;

gg g[N];
int dp[N][LN], lvl[N], start[N], finish[N], id[2*N];
int t = 0, n;

struct node{
	int val,delta;
	node*left,*right;
	node(int x): val(x), left(NULL), right(NULL), delta(0){}
}*root;

node* init(int l = 0, int r = 2*N -1)
{
	node*root = new node(0);
	if(l == r) return root;
	int m = (l+r)/2;
	root->left = init(l,m);
	root->right = init(m+1,r);
	return root;
}

void propagate(node*root)
{
	root->left->delta += root->delta;
	root->right->delta += root->delta;
	root->delta = 0;
	return;
}

void range_update(node*root,int ql, int qr,int val, int l = 0, int r = 2*N-1)
{
	if(qr<l||r<ql) return;
	if(ql<=l&&r<=qr)
	{
		if(l==r) 
		{
			root->val += (root->delta + val);
			root->delta = 0;
		}
		else root->delta += val;
		return;
	}

	int m = (l+r)/2;
	propagate(root);
	if(qr<=m)
		range_update(root->left,ql,qr,val,l,m);
	else if(ql>m)
		range_update(root->right,ql,qr,val,m+1,r);
	else {
		range_update(root->left,ql,qr,val,l,m);
		range_update(root->right,ql,qr,val,m+1,r);
	}
}


int distance(node*root, int pos, int l = 0, int r = 2*N-1)// this returns the number of broken bridges from root to the node at id[pos]
{
	if(l==r) {
		root->val += root->delta;
		root->delta = 0;
		return (root->val);
	}
	int m = (l+r)/2;
	propagate(root);
	if(pos<=m) return distance(root->left,pos,l,m);
	else return distance(root->right,pos,m+1,r);
}

void dfs(int u, int p = -1)
{
	if(p==-1) lvl[u] = 0;
	start[u] = t++;
	id[start[u]] = u;
	for(int i = 1; i < LN; i++)
		dp[u][i] = dp[dp[u][i-1]][i-1];
	for(auto v : g[u])
	{
		if(v == p) continue;
		dp[v][0] = u;
		lvl[v] = lvl[u] + 1;
		dfs(v,u);
	}
	finish[u] = t++;
	id[finish[u]] = u;
}

int lca(int u, int v)
{
	if(lvl[u] > lvl[v]) swap(u,v);
	RFOR(i,LN-1,0)
	if((lvl[v] - (1<<i)) >= lvl[u])
		v = dp[v][i];

	if(u == v) return u;

	RFOR(i,LN-1,0)
	if(dp[u][i] != dp[v][i])
		u = dp[u][i], v = dp[v][i];
	return dp[u][0];
}

int dist(int u, int v) // simple path distance from u to v
{
	int ret = lvl[u] + lvl[v] - 2*lvl[lca(u,v)];
	return ret;
}

int brokenbridges(int u, int v) // Returns number of broken bridges in simple path from u to v
{
	if(lvl[v] < lvl[u]) swap(u,v);
	if(start[u] > start[v]) swap(u,v);
	int ret = distance(root,start[u]) + distance(root,start[v]) - 2*distance(root,start[lca(u,v)]);
	return ret;
}

void disconnect(int u, int v) // Update the hanging subtree range by 1 Since all have 1 broken bridge from root
{
	if(lvl[v] < lvl[u]) swap(u,v);
	range_update(root,start[v],finish[v],1);
}

void connect(int u, int v) // Update the hangin subtree range by -1 To remove broken bridge
{
	if(lvl[v] < lvl[u]) swap(u,v);
	range_update(root,start[v],finish[v],-1);
}

void printstatus()
{
	for(int i = 0; i < 2*n; i++)
		cout<<distance(root,i)<<" ";
	cout<<endl;
}

void printId()
{
	for(int i = 0; i < 2*n; i++)
		cout<<id[i]<<" ";
	cout<<endl;
}

void printlvl(){
    for(int i = 1; i <= n; i++) cout<<lvl[i]<<" ";
    cout<<endl;
}

int main()
{
	cin>>n;
	root = init();
	int u,v; 
	FOR(i,1,n-1)
	{
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}

	dfs(1);

	int q;
	cin>>q;
    set<pair<int,int> > st;
	while(q--)
	{

		char c; int x,y; cin>>c>>x>>y;
        if(x>y) swap(x,y);
		if(c=='d') 
        {
            if(st.count({x,y}) == 0 && (dp[x][0] == y || dp[y][0] == x))
            disconnect(x,y),st.insert({x,y});
        }
		else if(c=='c') 
        {
            if(st.count({x,y}))
            connect(x,y),st.erase({x,y});
        }
		else {
			if(brokenbridges(x,y)!=0)
				cout<<"Impossible"<<endl;
			else cout<<dist(x,y)<<endl;
		}
	}
	return 0;
}
