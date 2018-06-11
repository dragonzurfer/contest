#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){

	ll n,k,q,x,bidder,bid,heighestbidder,heighestbid,secondheighestbidder;
	cin>>n;
	vector< vector<ll> > b(n+1);
	vector< pair<int,int> >bindex;
	for(int i=0;i<n;i++)
		{cin>>bidder>>bid,b[bidder].push_back(bid);}

	for(int i=0;i<n+1;i++)
		if(b[i].size())
			bindex.push_back(make_pair(b[i].back(),i));

	int t;
	sort(bindex.begin(),bindex.end());
	reverse(bindex.begin(),bindex.end());
	cin>>q;
	while(q--){

		cin>>k;set<int> absentBidders;
		while(k--)
			cin>>x,absentBidders.insert(x);

		heighestbidder=0;
		while(heighestbidder<bindex.size()&&absentBidders.count(bindex[heighestbidder].second))
			heighestbidder++;

		if(heighestbidder==bindex.size())
			{cout<<"0 0"<<endl;continue;}
		secondheighestbidder=heighestbidder+1;

		cout<<bindex[heighestbidder].second<<" ";//highest bidders number

		while(secondheighestbidder<bindex.size()&&absentBidders.count(bindex[secondheighestbidder].second))
			secondheighestbidder++;
		

		if(secondheighestbidder==bindex.size())
			cout<<b[bindex[heighestbidder].second][0]<<"\n";
		else{
			ll ans=*upper_bound(b[bindex[heighestbidder].second].begin(),
				b[bindex[heighestbidder].second].end(),b[bindex[secondheighestbidder].second].back());
			cout<<ans<<"\n";
		}
	
	}

	return 0;

}