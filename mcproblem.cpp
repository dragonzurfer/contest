#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

struct state
{
	ll ml,cl,mr,cr,boat=0;
	state* parent;
};

void printNode(state*st)
{
	cout<<"<"<<st->ml<<","<<st->cl;
	cout<<","<<st->mr<<","<<st->cr;
	cout<<","<<st->boat<<"> ";
}
bool isGoal(state*st)
{
	if(st->cl==0&&st->ml==0)
		return true;
	else
		return false;
}

bool isValid(state*st)
{
	if(st->ml>=0&&st->mr>=0
		&& st->cl>=0 and st->cr>=0
		&&(st->ml==0||st->ml>=st->cl)
		&&(st->mr==0||st->mr>=st->cr))
		return true;
	else
		return false;
}

ll helper(state*st)
{
	ll r=st->ml*10000+st->cl*1000+st->mr*100+st->cr*10+st->boat;
	return r;
}

state* assign(state*st,int cl,int ml,int boat,int cr,int mr)
{
	st->ml=ml;
	st->mr=mr;
	st->cl=cl;
	st->cr=cr;
	st->boat=boat;
	return st;
}

vector<state*> findNextStates(state*cs)
{
	ll csmr=cs->mr;
	ll csml=cs->ml;
	ll cscr=cs->cr;
	ll cscl=cs->cl;
	ll csb=cs->boat;

	vector<state*>children;
	state *newState1=new state;
	state* newState2=new state;
	state* newState3=new state;
	state* newState4=new state;
	state* newState5=new state;
	if(cs->boat==1)
	{
		//cout<<"\nleft";
		//Two missionaries cross left to right.
		newState1=assign(newState1,cscl,csml-2,0,cscr,csmr+2);
		if(isValid(newState1)){
			newState1->parent=cs;
			children.push_back(newState1);
		}
		//Two cannibals cross left to right.
		newState2=assign(newState2,cscl-2,csml,0,cscr+2,csmr);
		if(isValid(newState2)){
			newState2->parent=cs;
			children.push_back(newState2);
		}
		//One missionary and one cannibal cross left to right.
		newState3=assign(newState3,cscl-1,csml-1,0,cscr+1,csmr+1);
		if(isValid(newState3)){
			newState3->parent=cs;
			children.push_back(newState3);
		}
		//One missionary crosses left to right.
		newState4=assign(newState4,cscl,csml-1,0,cscr,csmr+1);
		if(isValid(newState4)){
			newState4->parent=cs;
			children.push_back(newState4);
		}
		// One cannibal crosses left to right.
		newState5=assign(newState5,cscl-1,csml,0,cscr+1,csmr);
		if(isValid(newState5)){
			newState5->parent=cs;
			children.push_back(newState5);
		}

	}
	else
	{
		//cout<<"\nright";
		//Two missionaries cross right to left.
		newState1=assign(newState1,cscl,csml+2,1,cscr,csmr-2);
		if(isValid(newState1)){
			newState1->parent=cs;
			children.push_back(newState1);
		}
		//Two cannibals cross right to left.
		newState2=assign(newState2,cscl+2,csml,1,cscr-2,csmr);
		if(isValid(newState2)){
			newState2->parent=cs;
			children.push_back(newState2);
		}
		//One missionary and one cannibal cross right to left.
		newState3=assign(newState3,cscl+1,csml+1,1,cscr-1,csmr-1);
		if(isValid(newState3)){
			newState3->parent=cs;
			children.push_back(newState3);
		}
		//One missionary crosses right to left.
		newState4=assign(newState4,cscl,csml+1,1,cscr,csmr-1);
		if(isValid(newState4)){
			newState4->parent=cs;
			children.push_back(newState4);
		}
		// One cannibal crosses right to left.
		newState5=assign(newState5,cscl+1,csml,1,cscr-1,csmr);
		if(isValid(newState5)){
			newState5->parent=cs;
			children.push_back(newState5);
		}

	}
	return children;
}
state* bfs()
{
	state* root=new state;
	root->ml=3;root->cl=3;root->boat=1;
	root->mr=0;root->cr=0;
	root->parent=NULL;
	if( isGoal(root))
		return root;

	vector<state*>children;
	stack<state*>tree;
	set<ll>storedNodes;
	set<ll>seenNodes;
	ll lastseenstate=0,currentseenstate=0,ltolstate=0;
	tree.push(root);//add root to the tree
	storedNodes.insert(helper(root));//add a copy to storedNodes for checking later
	int t;
	while(!tree.empty())
	{
		state*cs=tree.top();tree.pop();
		storedNodes.erase(helper(cs));
		if(isGoal(cs))//check if puzzle is over
			return cs;

		ll encode=helper(cs);
		seenNodes.insert(encode);//add current state to seen states to avoid looking at duplicate states
		children=findNextStates(cs);//get the next set of valid states
		
		//cout<<"\nseenNodes:";
		//for(auto&j:seenNodes)
		//	cout<<j<<",";
		//cout<<"\nstoredNodes:";
		//for(auto&j:storedNodes)
		//	cout<<j<<",";
		//cout<<"\ncurrentNode:"<<encode<<endl;
		//for(auto&child:children)
		//	printNode(child);
		//cin>>t;
		currentseenstate=encode;
		for(auto&child:children)
		{
			ll cencode=helper(child);
			if(seenNodes.count(cencode)==0||storedNodes.count(cencode)==0&&currentseenstate!=ltolstate)
			{//if the state was never seen before add it to the tree
				storedNodes.insert(cencode);
				tree.push(child);//add to the tree
				//cout<<"\ncount:"<<seenNodes.count(cencode);
				//cout<<"\nadded:";printNode(child);
				//cout<<endl;
				//for(auto&j:storedNodes)
				//cout<<j<<",";
				//cin>>t;
			}

		}
		ltolstate=lastseenstate;
		lastseenstate=encode;
	}
	return NULL;
}

void findpath(state*ans)
{
	while(ans->parent!=NULL)
	{
		cout<<helper(ans)<<endl;
		ans=ans->parent;
	}
}

int main()
{
	state*ans=bfs();
	cout<<"\nsolution\n";
	findpath(ans);
	return 0;
}