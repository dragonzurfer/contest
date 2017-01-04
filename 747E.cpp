#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
	

vector<string> split(string s, char d) {
    vector<string> res;
    for (int i = 0; i <= s.size(); i++) {
        int j = i;
        while (i < s.size() && s[i] != d) {
            i++;
        }
        res.push_back(s.substr(j, i - j));
    }
    return res;
}

int main() {
    string s;
    cin >> s;
    auto sp = split(s, ',');
    vector< vector<string> > v;
    stack<int>stk;
    stk.push(1000000);// string is atmost 10^6 long
    for(int i=0;i<sp.size();i+=2)
    {
    	string s=sp[i];
    	int num=atoi(sp[i+1].data());
    	stk.top()--;

    	if(v.size()<stk.size())
    		v.push_back(vector<string>());

    	v[stk.size()-1].push_back(s);//stack size denotes the level
    	
    	stk.push(num);
    	while(stk.top()==0)
		stk.pop();

    }
    cout<<v.size()<<endl;
    for(auto&i:v)
   	{
   		for(auto&j:i)
   			cout<<j<<" ";
   		cout<<endl;
   	}
    return 0;
}