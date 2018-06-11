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

bool regulari(string s)
{
    stack<char> st;
    for(auto val : s)
    {
        if(val == '(')
            st.push(val);
        else {
            if(!st.empty() && st.top() == '(')
                st.pop();
            else {
                st.push(val);
            }
        }
    }
    return st.empty();
}
bool isleft = false;
ll check(string s)
{
    stack<char> st;
    isleft = false;
    for(auto val : s)
    {
        if(val == '(')
            st.push(val);
        else {
            if(!st.empty() && st.top() == '(')
                st.pop();
            else {
                st.push(val);
            }
        }
    }
    if(st.top() == '(')
    {
        ll left = 0;
        while(!st.empty() && st.top() == '(')
        {
            left++;
            st.pop();
        }
        if(!st.empty())
            return -1;
        isleft = true;
        return left;
    } else {
        ll right = 0;
        while(!st.empty() && st.top() == ')')
        {
            right++;
            st.pop();
        }
        if(!st.empty())
            return -1;
        return right;
    }
}

int main()
{
    ll n;cin>>n;
    ll sep = 0, regular = 0, incomplete = 0;
    ll left[312345],right[312345];
    clr(left);
    
    FOR(i,0,n-1)
    {
        string s;cin>>s;
        if(regulari(s))
        {
            regular += 1;
            sep++;
        } else {
            auto cnt = check(s);
            if(cnt == -1) continue;
            if(!isleft)
            {
                right[cnt] += 1;
                incomplete += left[cnt];
            }
            else {
                left[cnt] += 1;
                incomplete += right[cnt];
            }
        }
    }
    ll ans =  regular*(regular-1) + sep + incomplete;
    cout<<ans;
     return 0;
}
