#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

int main()
{
    ll t;cin>>t;
    set<ll>infected;
    
    while(t--)
    {
        
        ll n,v,e,pn; cin>>n;
        list<ll>tree[n+1];
        set<pair<ll,ll> >p;
        
        for(ll i=1;i<n+1;i++)
            cin>>pn,p.insert(make_pair(pn,i));

        for(ll i=0;i<n-1;i++)
            cin>>v>>e,tree[v].push_back(e),tree[e].push_back(v);

        for(ll i=1;i<n+1;i++)
        {
        	set<ll>infected;
        	ll currentCapitalPlanet=0;
        	infected.insert(i);
        	for(auto&k:tree[i])
        		infected.insert(k);
        	
        	for(auto i=p.rbegin();i!=p.rend();++i)
        		if(infected.count(i->second)==0){
        			currentCapitalPlanet=i->second;
        			break;
        		}
        	cout<<currentCapitalPlanet<<" ";
        }
      
    }
    
}
