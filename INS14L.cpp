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
#define LSOne(S) (S & (-S))
typedef long long ll;

const int MAXN = 100005;
const int MAXM = 100005;
const int LN = 19;
int N;
ll N2,M, x,k, cur, B1[MAXN],B2[MAXN],val[MAXN], LVL[MAXN], DP[LN][MAXN];

int BL[MAXN << 1],ID[MAXN << 1];
int l[MAXN], r[MAXN];

vector < int > adjList[MAXN];
 
 
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

// Point query
// Returns value at position b in the array for ft = B1
// Returns value to be subtracted from query(B1, b) * b for ft = B2
ll query1(ll* ft, int b)	{
	ll sum = 0;
	for (; b; b -= LSOne(b)) sum += ft[b];
	return sum;
}

// Range query: Returns the sum of all elements in [1...b]
ll query(int b) {
    return (query1(B1, b) * b - query1(B2, b));
}

// Range query: Returns the sum of all elements in [i...j]
ll range_query(int i, int j)    {
    return query(j) - query(i - 1);
}

// Point update: Adds v to the value at position k in the array
// ft is the fenwick tree which represents that array
void update(ll* ft, int k, ll v) {
	for (; k <= N; k += LSOne(k)) ft[k] += v;
}

// Range update: Adds v to each element in [i...j]
void range_update(int i, int j, ll v)	{
	update(B1, i, v);
	update(B1, j + 1, -v);
	update(B2, i, v * (i - 1));
	update(B2, j + 1, -v * j);
}

void update(int p,int u,int par)
{
	
	// modify(u,x+(LVL[p]-LVL[u]+1)*k);
	range_update(l[u],l[u],x+(LVL[p]-LVL[u]+1)*k);
	// modify(N+r[u],x+(LVL[p]-LVL[u]+1)*k);
	for (int i = 0; i < adjList[u].size(); i++){
		int v = adjList[u][i];
		if (v == par) continue;
		//LVL[v] = LVL[u] + 1;
		//DP[0][v] = u;
		update(p,v, u);
	}
}
  
int main(){
 
	int p, v;
 
	while (scanf("%d", &N) != EOF){
 
		// Cleanup
		cur = 0;
		for (int i = 1; i <= N; i++) adjList[i].clear();
 
		// Inputting Tree
		for (int i = 2; i <= N; i++){
			scanf("%d", &p);
			adjList[p].push_back(i);
			// adjList[i].push_back(p);
		}
		// Preprocess
		DP[0][1] = 1;
		dfs(1, -1);
		cout<<"DONE:";int ti;cin>>ti;
 		// range_update(0,100000,0);
		
		// int size = sqrt(cur);

		cout<<endl;
		ll u,t,left,right;

 		while(1)
 			{
 				// cout<<"\nVAL:";
 				// for(int i=0;i<2*N+1;i++)
 				// 	cout<<ID[i]<<" ";
 				// cout<<"\nVAL:";
 				// for(int i=0;i<=30;i++)
 				// 	cout<<A[i]<<" ";
 				// cout<<endl;
 				cout<<"\n query:";
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
 					cout<<range_query(left,right)<<endl;
 				}
 			}
	}
}