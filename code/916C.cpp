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
    int n,m;
    cin>>n>>m;
    vector<bool> is(312345,false); 
    vector<int>primes;
    for(int i = 2; i < 312345; i++)
		if(!is[i])
		{
			primes.pb(i);
			for(ll j = 1LL * i * i; j < 312345; j += i)
				is[j] = 1;
		}
    int k = lower_bound(primes.begin() , primes.end() , n) - primes.begin();
	  k = primes[k];
    
    cout<<k<<" "<<k<<endl;
    
    FOR(i,1,n-2)
        cout<<i<<" "<<i+1<<" 1"<<endl;
    cout<<n-1<<" "<<n<<" "<<k-(n-2)<<endl;
    
    m = m-n+1;
    
    FOR(i,1,n)
    {
        FOR(j,i+2,n)
        {
            if(!m) break;
            m--;
            cout<<i<< " "<<j<<" 60004000"<<endl;
        }
    }
    
   return 0;
}
