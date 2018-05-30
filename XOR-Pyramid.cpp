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

int main() {
    int n,q;
    cin>>n;
    vector<int>A(n);
    FOR(i,0,n-1)cin>>A[i];
    vector<vector<int> > dp(n,vector<int>(n));
    FOR(i,0,n-1)
        dp[0][i] = A[i];
    FOR(i,1,n-1)
    {
        FOR(j,0,n-i)
            dp[i][j] = dp[i-1][j] ^ dp[i-1][j+1]; 
    }
    FOR(i,1,n-1)
    {
        FOR(j,0,n-i)
            dp[i][j] = max(dp[i][j],max(dp[i-1][j],dp[i-1][j+1])); 
    }
    cin>>q;
    while(q--)
    {
        int l,r; cin>>l>>r;
        // l--,r--;
        cout<<dp[r-l][l-1]<<endl;
    }
    return 0;
}
