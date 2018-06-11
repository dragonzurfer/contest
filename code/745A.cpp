#include<bits/stdc++.h>

using namespace std;

typedef long long ll;


int main()
{
	string s;cin>>s;
	list<char>l;

	for(int i=0;i<s.length();i++)
		l.push_back(s[i]);
	
	set<list<char> >v;
	int k=0;

	while(k++!=s.length())
	{
		char f=l.back();l.pop_back();
		l.push_front(f);
		v.insert(l);    
	}
	cout<<v.size();
	return 0;
}