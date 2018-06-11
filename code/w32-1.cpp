#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define vll vector<ll>
#define F first
#define S second
#define pll pair<ll,ll>
#define FOR1(i,a) for(i=0;i<=a;i++)
#define FOR2(i,a,b) for(i=a;i<=b;i++)
#define endl '\n'
#define clr(a) memset(a,0,sizeof(a))
#define all(x) x.begin(),x.end()

#define REP(i,a,b)  for (int i = int(a); i < int(b); i++)
typedef long long LL;

uint32_t flp2 (uint32_t x)
{
    x = x | (x >> 1);
    x = x | (x >> 2);
    x = x | (x >> 4);
    x = x | (x >> 8);
    x = x | (x >> 16);
    return x - (x >> 1);
}

int val[]={0,1};
LL previous_power_of_2;

int invert(int v)
{
    if(v)
        return 0;
    else
        return 1;
}

int sol(int k,bool flip)
{

    if(k<2)
        if(flip)
            return invert(val[k-1]);
        else
            return val[k-1];
    
    if(!(k&(k-1)))
        previous_power_of_2=flp2(k-1);
    else
        previous_power_of_2=flp2(k);

    k=k-previous_power_of_2;
    
    if(flip)
        sol(k,false);
    else
        sol(k,true);
}

int main() {
    int t;
    cin>>t;

    while(t--)
    {
        LL k;cin>>k;
        cout<<invert(sol(k+1,true));
    }
    return 0;
}