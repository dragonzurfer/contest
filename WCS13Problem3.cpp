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
int inv(int a, int b){
 return 1<a ? b - inv(b%a,a)*b/a : 1;
}

ll read_ll(){char c=gc();while((c<'0'||c>'9')&&c!='-')c=gc();ll ret=0;int neg=0;if(c=='-')neg=1,c=gc();while(c>='0'&&c<='9'){ret=10*ret+c-48;c=gc();}return neg?-ret:ret;}

void solve()
{
    ll n,m,k,answer = 0;
    n = rll m = rll k = rll
    
    vector<ll>A(n),product(n),zeroes;
    zeroes.pb(-1);
    FOR(i,0,n-1)
    {
        cin>>A[i];
        if(A[i]%m == 0)
            zeroes.pb(i);
        A[i]%=m;
    }
    zeroes.pb(A.size());
    product[0] = A[0];
    FOR(i,1,n-1)
    {
        if(product[i-1] == 0) product[i] = A[i];
        else 
        product[i] = (A[i]*product[i-1])%m;
    }
    
    unordered_map<ll,ll>hash;
    FOR(i,0,n-1)
    {
        if(product[i] == 0)
        {
            hash.clear();
            continue;
        }
        if(product[i] == k)
            answer++;
        if(hash.find(product[i]) != hash.end())
            answer += hash[product[i]];
        auto insert = (product[i]*k)%m;
        if(hash.find(insert) != hash.end())
            hash[insert] += 1;
        else hash.insert({insert,1});
    }
    
    if(k==0)
    {
        for(int j=1;j<zeroes.size()-1;j++)
        {
            answer+= (zeroes[j]+1)*(zeroes[j+1]-zeroes[j]);
        }
    }
    
    cout<<answer<<endl;
}

int main()
{
    // cout<<inv(2,3)<<endl;
    int t;cin>>t;
    while(t--)
    {
        solve();
    }
   return 0;
}
