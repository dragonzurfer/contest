
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
#define gc getchar
#define pc putchar

typedef long long ll;
vector<int>elements;
void make_set(vector<ll> &id, vector<ll> &rank, ll n) {
	elements.resize(n+1);
    for(ll i=1; i<=n; i++) {
        id[i] = i;
        rank[i] = 1;
        elements[i] = 1;
    }
}
ll find_set(vector<ll> &id, ll p) {
    ll root = p;
    //find the root
    while(root != id[root]) {
        root = id[root];
    }
    //perform path compression
    while(p != root) {
        ll newp = id[p];
        id[p] = root;
        p = newp;
    }
    return root;
}
void merge_set(vector<ll> &id, vector<ll> &rank, ll x, ll y) {
    x = find_set(id, x);
    y = find_set(id, y);
    if(rank[x] > rank[y])
        id[y] = x,elements[x]+=elements[y];
    else
        id[x] = y,elements[y]+= elements[x];
    if(rank[x] == rank[y])
        rank[y] += 1;
}


int main()
{
 int q;
  cin>>q;
  vector<ll>id(100005),rank(100005);
  while(q--)
  {
	ll n,m,c,l;
    cin>>n>>m>>l>>c;
    make_set(id,rank,n);
    FOR(i,1,m)
    {
      ll u,v;
      cin>>u>>v;
      if(find_set(id,u)!=find_set(id,v))
        merge_set(id,rank,u,v);
    }
    bool other = false;
    if(c>l)
      other = true;
      ll cnt = 0,cmp=0;
      ll cost=0;
    FOR(i,1,n)
      if(id[i]==i)cmp+=((elements[i]-1)*c+l),cnt+=elements[i],cost+=min((cnt*l),cmp),cnt=0,cmp=0;
    cout<<cost<<endl;
  
  }
}












