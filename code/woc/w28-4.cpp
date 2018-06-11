#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void make_set(ll p[],ll r[],ll ne[],ll x)
{
	p[x]=x;
	r[x]=0;
	ne[x]=1;
}

ll find_set(ll p[],ll r[],ll ne[],ll x)
{
	while(p[x]!=x)
	{
		x=p[x];
	}
	return p[x];
}

ll link(ll p[],ll r[],ll ne[],ll x,ll y)
{
	if(r[x]>r[y]){
		//ne[x]+=1;
		p[y]=x;
	}
	else
	{
		//ne[y]+=1;
		p[x]=y;
		if(r[x]==r[y])
			r[y]+=1;
	}
	
}
void union_(ll p[],ll r[],ll ne[],ll x,ll y)
{
	ll px=find_set(p,r,ne,x),py =find_set(p,r,ne,y),rval;
	//rval=2*ne[px]*ne[py];
	
	//cout<<"k1:"<<ne[px]<<","<<"k2:"<<ne[py]<<endl;
	link(p,r,ne,px,py);
	//ll nx=find_set(x);
	ne[find_set(p,r,ne,x)]=ne[px]+ne[py];
	//return rval;
	//cout<<find_set(x)<<":"<<ne[find_set(x)];int t;cin>>t;
}

int main()
{
	ll t,o;
	cin>>t;
	while(t--)
	{

		ll n,e,fval=0;
		ll p[1000],r[1000],ne[1000];
		cin>>n>>e;

		for(int i=1;i<n+1;i++)
			make_set(p,r,ne,i);

		map<ll,ll>edgecount;
		set<ll>components;
		while(e--)
		{
			ll u,v;
			cin>>u>>v;
			if(find_set(p,r,ne,u)!=find_set(p,r,ne,v))
			{
				union_(p,r,ne,u,v);
				components.insert(find_set(p,r,ne,u));
			}
			ll root=find_set(p,r,ne,u);
			edgecount[root]+=1;	
		}

		//for(auto&i:components)
		//{
		//	if(p[i]=i)
		//	{
		//		ll nodes=ne[i];
		//		ll maxfval=((nodes-1)*nodes*(nodes+1))/3+(components[i]-nodes+1)*(nodes*(nodes-1));
		//		//ll e=components[i];
		//		sum=sum+maxfval;
		//	}
		//}
		ll sum=0,excess=0;
		fval=0;
		for(auto&i:components)
		{
			//cout<<i<<" :"<<ne[i]<<endl;
			
			sum=sum+(((ne[i]-1)*(ne[i])*(ne[i]+1))/3+fval*(ne[i]-1));
			fval=fval+(ne[i]-1)*(ne[i]);
			excess=excess+edgecount[i]-ne[i]+1;
			//cout<<"fval:"<<fval;cin>>o;

		}
		//cout<<excess;
		sum=sum+excess*fval;
		cout<<sum<<endl;
		
	}
	return 0;
}