#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    vector<ll>bag;
    ll n,currentCandyCount=1,sum=1;cin>>n;
    
    while(sum<=n)
        bag.push_back(currentCandyCount),sum+=++currentCandyCount;
    
    sum-=currentCandyCount;
    if(sum!=n&&bag.size())
        bag.back()+=n-sum;
    
    cout<<bag.size()<<endl;
    for(auto&i:bag)
        cout<<i<<" ";

    return 0;
}
