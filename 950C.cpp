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



int main()
{
    string s; cin>>s;
    int n = s.length();
    vector<int> ans[n]; int k = 0;
    vector<int>zero,one;
    if(s[0] == '1'||s[n-1] == '1') return !printf("-1");
    zero.pb(0);
    ans[k++].pb(0);
    
    FOR(i,1,n-1)
    {
        if(s[i] == '1')
        {
            if(zero.size() == 0) return !printf("-1");
            else {
                auto pos = zero.back(); zero.pop_back();
                ans[pos].pb(i); one.pb(pos);
            }
        } else {
            if(one.size()==0)
                zero.pb(k),ans[k++].pb(i);
            else {
                auto pos = one.back(); one.pop_back();
                ans[pos].pb(i); zero.pb(pos);
            }
        }
    }
    if(one.size()>0) return !printf("-1");
    cout<<k<<endl;
    for(auto sol : ans)
    {
        if(sol.size()==0) break;
        cout<<sol.size();
        for(auto val : sol)
            cout<<" "<<val+1;
        cout<<endl;
    }
    return 0;
}











