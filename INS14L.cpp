#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define vll vector<ll>
#define F first
#define S second
#define pll pair<ll,ll>
#define FOR1(i,a) for(i=0;i<=a;i++)
#define FOR2(i,a,b) for(i=a;i<=b;i++)
#define endl '\n'
#define clr(a) memset(a,0,sizeof(a))
#define all(x) x.begin(),x.end()
typedef long long ll;

const int MAXN = 100005;
const int MAXM = 100005;
const int LN = 19;

int N,N2,M, x,k, cur, A[2*MAXN+1],val[MAXN], LVL[MAXN], DP[LN][MAXN];

int BL[MAXN << 1],ID[MAXN << 1];
int l[MAXN], r[MAXN];

vector < int > adjList[MAXN];
 
struct query{
	int id, l, r, lc;
	bool operator < (const query& rhs){
		return (BL[l] == BL[rhs.l]) ? (r < rhs.r) : (BL[l] < BL[rhs.l]);
	}
}Q[MAXM];
 
// Set up Stuff
void dfs(int u, int par){
	l[u] = ++cur; 
	ID[cur] = u;
	for (int i = 1; i < LN; i++) DP[i][u] = DP[i - 1][DP[i - 1][u]];
	for (int i = 0; i < adjList[u].size(); i++){
		int v = adjList[u][i];
		if (v == par) continue;
		LVL[v] = LVL[u] + 1;
		DP[0][v] = u;
		dfs(v, u);
	}
	r[u] = ++cur; ID[cur] = u;
}
 
// Function returns lca of (u) and (v)
inline int lca(int u, int v){
	if (LVL[u] > LVL[v]) swap(u, v);
	for (int i = LN - 1; i >= 0; i--)
		if (LVL[v] - (1 << i) >= LVL[u]) v = DP[i][v];
	if (u == v) return u;
	for (int i = LN - 1; i >= 0; i--){
		if (DP[i][u] != DP[i][v]){
			u = DP[i][u];
			v = DP[i][v];
		}
	}
	return DP[0][u];
}

void build() {  // build the tree
  for (int i = N2 - 1; i > 0; --i) A[i] = A[i<<1] + A[i<<1|1];
}

void modify(int p, int value) {  // set value at position p
  for (A[p += N2] = value; p > 1; p >>= 1) A[p>>1] = A[p] + A[p^1];
}

int query(int l, int r) {  // sum on interval [l, r)
  int res = 0;
  for (l += N2, r += N2; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += A[l++];
    if (r&1) res += A[--r];
  }
  return res;
}

void update(int p,int u,int par)
{
	
	// modify(u,x+(LVL[p]-LVL[u]+1)*k);
	modify(l[u],x+(LVL[p]-LVL[u]+1)*k);
	// modify(N+r[u],x+(LVL[p]-LVL[u]+1)*k);
	for (int i = 0; i < adjList[u].size(); i++){
		int v = adjList[u][i];
		if (v == par) continue;
		//LVL[v] = LVL[u] + 1;
		//DP[0][v] = u;
		update(p,v, u);
	}
}
// int main() {
//   scanf("%d", &n);
//   for (int i = 0; i < n; ++i) scanf("%d",  + n + i);
//   build();
//   modify(0, 1);
//   printf("%d\n", query(3, 11));
//   return 0;
// }
  
int main(){
 
	int p, v;
 
	while (scanf("%d", &N) != EOF){
 
		// Cleanup
		cur = 0;
		for (int i = 1; i <= N; i++) adjList[i].clear();
 
		// Inputting Tree
		A[1]=0;
		for (int i = 2; i <= N; i++){
			scanf("%d", &p);
			adjList[p].push_back(i);
			// adjList[i].push_back(p);
		}
 
		// Preprocess
		DP[0][1] = 1;
		dfs(1, -1);
		N2=2*N+1;
		for(int i=0;i<N2;i++)
			A[N2+i]=0;
		// int size = sqrt(cur);
		build();
		cout<<endl;
		ll u,t,left,right;

 		while(1)
 			{
 				cout<<"\nVAL:";
 				for(int i=0;i<2*N+1;i++)
 					cout<<ID[i]<<" ";
 				cout<<"\nVAL:";
 				for(int i=0;i<=30;i++)
 					cout<<A[i]<<" ";
 				cout<<endl;
 				cin>>t;
 				if(t==1)
 				{
 					cin>>u>>x>>k;
 					cout<<endl<<u<<" "<<x<<" "<<k;
 					update(u,u,-1);
 				}
 				else
 				{
 					cin>>u;
 					left=l[u];right=r[u];
 					cout<<"\nleft:"<<left<<" right:"<<right<<endl;
 					cout<<query(left,right)<<endl;
 				}
 			}
	}
}