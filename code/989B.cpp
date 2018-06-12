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

int main()
{
    int n,p; cin>>n>>p;
    string s;cin>>s;
    vector<char> a(n);
    FOR(i,0,n-1) a[i] = s[i];
    FOR(i,0,n-1-p)
    {
        if(a[i]!=a[i+p] ||a[i] == a[i+p] && a[i] == '.' )
        {
            FOR(j,0,n-p-1)
            {
                if(a[j]!=a[j+p] &&(a[j] == '.' || a[j+p] == '.'))
                {
                    int f = a[j] - '0';
                    int b = a[j+p] - '0';
                    if(a[j] == '.')
                        a[j] = (b^1)+'0';
                    else if(a[j+p] == '.') a[j+p] = (f^1)+'0';
                }else if(a[j] == a[j+p] && a[j] == '.'){
                        a[j] = '1'; a[j+p] = '0';
                    } 
            }
            FOR(ii,0,n-1) 
            {
              if(a[ii]=='.')a[ii] = '1';
                cout<<a[ii];
            }
            return 0;
        } 
    }
    cout<<"No";
    return 0;
}
