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
typedef int ll;

struct query
{
	ll r,l,fa;
	int ans;
};

ll cnt[100000],a[100000];
int rootn, answ;

bool block(query a,query b)
{
    
  if(floor(a.l/rootn)<floor(b.l/rootn))
      return true;
  else if(floor(a.l/rootn)>floor(b.l/rootn))
      return false;
  return a.r<b.r;
}

bool cmp(query a,query b)
{
  return a.ans<b.ans;
}

void insert(int pos)
{
//	cout<<endl<<"add "<<a[pos];
	cnt[a[pos]]++;
 	if(cnt[a[pos]]==1)
		answ++;
	
}
void remove(int pos)
{
//	cout<<endl<<"rem "<<a[pos];
	cnt[a[pos]]--;
	if(cnt[a[pos]] == 0)
		answ--;
}

int main()
{ 
	ios::sync_with_stdio(false);
	ll i,n,t,q,querylen;
	cin>>n;
	answ=0;	
	clr(a);
	FOR1(i,n-1)
	cin>>a[i];
	cin>>querylen;
	ll qcnt=0;
	while(qcnt!=querylen)
	{
		
	answ=0;
	if(querylen<100000)
		q=querylen;
	else
		q=100000;

	query qa[q];

	for(i=0;i<q;i++)
   	{	
   		ll l,rr;
 		cin>>l>>rr;
 		qcnt+=1;
		qa[i].l = l-1;
		qa[i].r = rr - 1;
		qa[i].ans = i;
 	}	

	clr(cnt);
	rootn=pow(n,0.5);

	sort(qa,qa+q,block);
	ll currentL=0,currentR=0;
  
	
	for(i=0;i<q;i++)
  	{
  		// int t;cin>>t;
      		while(currentL<qa[i].l)
          	{	remove(currentL);currentL++; }
      		while(qa[i].l<currentL)
          	{	insert(currentL-1);currentL--; }
      		while(currentR<=qa[i].r)
           	{	insert(currentR);currentR++;}
      		while(currentR>qa[i].r+1)
          	{	remove(currentR-1);
			currentR--;
		}

      		qa[qa[i].ans].fa=answ;
  	}
  	
	for(ll i=0;i<q;i++)
		cout<<qa[i].fa<<endl;
	}
	return 0;
}

