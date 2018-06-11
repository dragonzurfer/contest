#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,cnt=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int t; cin >>t;
        if(t%2==0)cnt++;
    }
    int ans = pow(3,n) - pow(2,cnt);
    cout<<ans; return 0;
}
