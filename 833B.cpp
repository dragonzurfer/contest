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
#define RFOR(i,a,b) for(i=a;i>=b;i--)
#define FOR(i,a,b) for(i=a;i<=b;i++)
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

ll read_ll(){char c=gc();while((c<'0'||c>'9')&&c!='-')c=gc();ll ret=0;int neg=0;if(c=='-')neg=1,c=gc();while(c>='0'&&c<='9'){ret=10*ret+c-48;c=gc();}return neg?-ret:ret;}
const int N=4e4;
const int K=55;

int dp[K][N],a[N];
int currentL,currentR,cnt[N],ans;
void add(int idx) { if(++cnt[a[idx]]==1) ++ans; }
void rem(int idx) { if(--cnt[a[idx]]==0) {//cout<<a[idx]<<" became 0"<<endl;
--ans; }}
int cal(int l,int r)
{
	// cout<<"l:"<<l<<" r:"<<r<<endl;
	while(currentR<r) currentR+=1,add(currentR);
	// for(int i=0;i<10;i++)
	// 	cout<<cnt[i]<<" ";cout<<endl;
	// int t;cout<<currentL<<" "<<currentR<<":"<<ans;cin>>t;
	int tt;
	while(l<currentL) currentL-=1,add(currentL);
	// for(int i=0;i<10;i++)
		// cout<<cnt[i]<<" ";cout<<endl;
	// cout<<currentL<<" "<<currentR<<":"<<ans;cin>>tt;

	while(currentL<l) rem(currentL),currentL+=1;
	// for(int i=0;i<10;i++)
		// cout<<cnt[i]<<" ";cout<<endl;
	// cout<<currentL<<" "<<currentR<<":"<<ans;cin>>tt;

	while(r<currentR) rem(currentR),currentR-=1;
	// for(int i=0;i<10;i++)
	// 	cout<<cnt[i]<<" ";cout<<endl;
	// cout<<currentL<<" "<<currentR<<":"<<ans;cin>>t;
	return ans;
}

// typedef struct Counter {
// 	int l,r,ans; //[l,r)
// 	int cnt[N+1];

// 	Counter() { l=r=ans=0; memset(cnt,0,sizeof(cnt)); }
// 	void add(int idx) { if(++cnt[a[idx]]==1) ++ans; }
// 	void rem(int idx) { if(--cnt[a[idx]]==0) --ans; }
// 	int calc(int ql,int qr) {
// 		assert(ql<=qr);
// 		while(ql<l) add(--l);
// 		while(qr>r) add(r++);
// 		while(ql>l) rem(l++);
// 		while(qr<r) rem(--r);
// 		//printf("[%d..%d)=%d\n",ql,qr,ans);
// 		return ans;
// 	}
// } Counter;
// Counter counter;
void solve(int l,int r,int pl,int pr,int k) {
	int m=(l+r)/2;
	int maxi=-1,val,nn=min(pr,m),i,pos=-1;
	FOR(i,pl,nn)
	{
		// cout<<"ans:"<<i<<" "<<m<<" :";int tt;cin>>tt;cout<<cal(i,m)<<endl;
		val=dp[k-1][i]+cal(i,m-1);
	
		if(val>maxi)
			maxi=val,pos=i;
	}
	dp[k][m]=maxi;
	if(l<m)solve(l,m-1,pl,pos,k);
	if(m<r)solve(m+1,r,pos,pr,k);
}

int main()
{
	int n,k,i;cin>>n>>k;
	FOR(i,0,n-1)
	a[i]=rll
	clr(dp);clr(cnt);
	cnt[a[0]]+=1;
	cnt[a[1]]+=1;
	currentR=1;currentL=0,ans=1;
	if(a[0]!=a[1])ans=2;
	// cout<<currentL<<" "<<currentR<<":"<<ans;
	// cout<<endl<<currentL<<" "<<currentR<<":"<<cal(currentL,currentR)<<":"<<endl;
	// int t;cin>>t;
	FOR(i,1,k)
	{
		solve(0,n,0,n,i);
	}
	// for(int i=0;i<=n;i++){
	// 	for(int j=0;j<=k;j++)
	// 		cout<<dp[j][i]<<" ";cout<<endl;
	// }

	cout<<dp[k][n];
	return 0;
}