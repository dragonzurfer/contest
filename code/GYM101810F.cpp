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

bool vis[1000001];
int isThere[1000001];
void solve()
{
    int maxi,n; 
    n = rll
    vector<int> A(n);
    clr(isThere);clr(vis);
    for(int i = 0; i < n; i++)
    {
        A[i] = rll
        isThere[A[i]] += 1;
    }
    ll sum = 0;
    for(int i = 0; i <= 1000000; i++)
    {
        if(isThere[i]>0)
        {
            for(int j = i; j <= 1000000; j += i)
            {
                if(isThere[j]>0&&!vis[j])
                {
                    sum += (ll) isThere[j]*i;
                    vis[j] = true;
                    // cout<<j<<" is there"<<endl;
                }
            }
        }
    }
    printf("%lld\n",sum);
}

int main()
{
    int t;
    t = rll
    while(t--)
    {
        solve();
    }
    return 0;
}
