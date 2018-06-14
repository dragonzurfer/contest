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

const int N = (int)1e5+5;
ll n, m;
vector<int> a(N), b(N), pa(N), pb(N);

ll solve(ll n, ll &k, ll &a, ll &b)
{
    if(n == 1) return 0;
    if(n%k!=0 && k <= n)
    {
        return n%k*a + solve(n-n%k,k,a,b);
    } else {
        if(k!=1 && k <= n)
            return min(b+solve(n/k,k,a,b),a*(n-1));
        else return a*(n-1);
    }
}

int main()
{
    ll n,k,a,b;
    cin>>n>>k>>a>>b;
    cout<<solve(n,k,a,b);
    return 0;
}
