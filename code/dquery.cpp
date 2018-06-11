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
#ifndef ONLINE_JUDGE
#define gc getchar
#define pc putchar
#else
#define gc getchar_unlocked
#define pc putchar_unlocked
#endif
typedef int ll;

struct query
{
	ll r,l,ans;
	int index;
};
int rootn, answ;

inline bool block(query a,query b)
{
    
  if(floor(a.l/rootn)<floor(b.l/rootn))
      return true;
  else if(floor(a.l/rootn)>floor(b.l/rootn))
      return false;
  return a.r<b.r;
}

inline bool cmp(query a,query b)
{
  return a.index<b.index;
}

int read_int() {
    char c = gc();
    while((c < '0' || c > '9') && c != '-') c = gc();
    int ret = 0, neg = 0;
    if (c == '-') neg = 1, c = gc();
    while(c >= '0' && c <= '9') {
        ret = 10 * ret + c - 48;
        c = gc();
    }
    return neg ? -ret : ret;
}

ll read_ll() {
    char c = gc();
    while((c < '0' || c > '9') && c != '-') c = gc();
    ll ret = 0;
    int neg = 0;
    if (c == '-') neg = 1, c = gc();
    while(c >= '0' && c <= '9') {
        ret = 10 * ret + c - 48;
        c = gc();
    }
    return neg ? -ret : ret;
}

int main()
{ 
	ll i,n,t,q,querylen;
	n=read_ll();
	answ=0;	
   vll a(n+1);
   vll cnt(1000005);
	FOR1(i,n-1)
	a[i]=read_ll();
	q=read_ll();

	vector<query> qa(q);

	for(i=0;i<q;i++)
   	{	
   		ll l,rr;
 		l=read_ll(),rr=read_ll();
		qa[i].l = l-1;
		qa[i].r = rr - 1;
		qa[i].index = i;
 	}	
 	vll answer(q,0);
	rootn=int(sqrt(n))+1;

	sort(all(qa),block);
	ll currentL=0,currentR=0;
  
	ll pos;
	for(i=0;i<q;i++)
  	{
      		while(currentL<qa[i].l)
          	{	
          		pos=currentL;
          		cnt[a[pos]]--;
          			if(cnt[a[pos]] == 0)
          				answ--;
          		currentL++; 
          	}
      		while(qa[i].l<currentL)
          	{	
          		pos=currentL-1;
      			cnt[a[pos]]++;
      		 	if(cnt[a[pos]]==1)
      				answ++;
          		currentL--; 
          	}
      		while(currentR<=qa[i].r)
           	{	
           		pos=currentR;
           		cnt[a[pos]]++;
           		 	if(cnt[a[pos]]==1)
           				answ++;
           		currentR++;
           	}
      		while(currentR>qa[i].r+1)
          	{	
          		pos=currentR-1;
          		cnt[a[pos]]--;
          			if(cnt[a[pos]] == 0)
          				answ--;
          		currentR--;
          	}

		qa[i].ans=answ;
  	}

  	sort(all(qa),cmp);
	for(ll i=0;i<q;i++)
		cout<<qa[i].ans<<endl;

	return 0;
}

