#include<bits/stdc++.h>

typedef long long ll;
using namespace std;
vector<vector<char> > r;
ll n,m;
bool lookdownB(int i,int j)
{
	if(i==n-1)
		return true;

	if(r[i+1][j]=='B')
		return true;
	else
		return false;
}
bool lookdownW(ll i,ll j)
{
	if(i==n-1)
		return true;
	if(r[i+1][j]=='B'||r[i+1][j]=='W')
		return true;
	return false;
}

bool isValidW(ll i,ll j)
{
	if(j-1>=0&&j+1<m&&lookdownW(i,j))
	{

		if(r[i][j-1]=='B'&&r[i][j+1]=='W')
			return true;
		
		if(r[i][j-1]=='W'&&r[i][j+1]=='B')
			return true;
		
		if(r[i][j-1]=='B'&&r[i][j+1]=='B')
			return true;
		
		if(r[i][j-1]=='W'&&r[i][j+1]=='W')
			return true;

	}

	return false;
}

int main()
{
	ll t;cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(auto&i:r)
			i.clear();
		for(int i=0;i<n;i++){
			r.push_back(vector<char>());
			for(int j=0;j<m;j++){
				char s;cin>>s;
				r[i].push_back(s);
			}
		}
		
		bool flag=false;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(r[i][j]=='A')
					continue;
				if(r[i][j]=='B'&&!lookdownB(i,j))
					{flag=true;cout<<"no\n";break;}
				if(r[i][j]=='W'&&!isValidW(i,j))
					{flag=true;cout<<"no\n";break;}
			}
			if(flag)
				break;

		}
		if(!flag)
			cout<<"yes\n";
	}
}