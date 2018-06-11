#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

int main(){
	ll n,front;
	queue<ll>D,R;
	string a;
	cin>>n;
	cin>>a;
	for(int i=0;i<n;i++){
		if(a[i]=='D')
			D.push(i+1);
		else
			R.push(i+1);
	}
	while(!D.empty()&&!R.empty()){
		char index;
		if(D.front()<R.front()){
			R.pop();
			front=D.front();
			front=front+n;
			D.pop();
			D.push(front);
			//cout<<"POPED FROM R";
		}
		else{
			D.pop();
			front=R.front();
			front=front+n;
			R.pop();
			R.push(front);
			//cout<<"POPED FROM D";
		}
		//remove comments to see queue status
		//queue<ll>t1,t2;
		//t1=D,t2=R;
		//cout<<"t1:";
		//while(!t1.empty())
		//{
		//	cout<<t1.front()<<"->";
		//	t1.pop();
		//}
		//cout<<"\nt2:";
		//while(!t2.empty())
		//{
		//	cout<<t2.front()<<"->";
		//	t2.pop();
		//}
		//int t;cin>>t;
	}
	if(D.empty())
		cout<<"R";
	else
		cout<<"D";
	return 0;
}