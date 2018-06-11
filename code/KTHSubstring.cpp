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
typedef int ll;
template<class T> inline T lcm(T a,T b){
        return a/gcd(a,b)*b;
}

ll read_ll(){char c=gc();while((c<'0'||c>'9')&&c!='-')c=gc();ll ret=0;int neg=0;if(c=='-')neg=1,c=gc();while(c>='0'&&c<='9'){ret=10*ret+c-48;c=gc();}return neg?-ret:ret;}

const int N = (int)1e5+10;

string s;
vector<int>pos[26];
map<char,bool>isThere;

bool cmp(int a,int b)
{
    int cnt = 1;
    while(a+cnt < s.length() && b+cn t< s.length() && s[a+cnt] == s[b+cnt])
        cnt++;
    if(a+cnt >= s.length())
        return false;
    return s[a+cnt] < s[b+cnt];
        
}

void fillPos(string s)
{
    int position = 0;
    for(auto c: s)
    {
        if(position+1 != s.size())
          pos[c-'a'].pb(position++);
        isThere[c] = true;
    }
    for(int i = 0; i < 26; i++)
    {
        sort(pos[i].begin(),pos[i].end(),cmp);
    }
}



int main()
{
    clr(pos);
    int k; cin>>s>>k;
    char search[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','x','y','z'};
    set<string>st;
    fillPos(s);
    for(auto c: search)
    {
        if(st.size() == k)break;
        if(isThere[c])
        {
            st.insert(string(1,c));
            int len = 1;
            for(auto position: pos[c-'a'])
            {
                while(len <= s.length() )
                {
                    st.insert(s.substr(position,len));
                    len+=1;
                }
            }
        }
    }
    int cnt = 1;
    for(auto ele:st)
        if(cnt == k)
        {
            cout<<ele;
            return 0;
        } else
            cnt++;
    
}

