#include <message.h>
#include <cassert>
#include <cstdio>
#include "nanobots.h"
#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int TN,MY;
int N;
ll R;
ll mo=1000000007;

void slow() {
	int i,j,k,l,r,x,y; string s;
	ll v;
	if(MY!=0) return;
	
	ll Y=R,X=1;
	vector<pair<ll,ll>> V;
	V.push_back({0,1LL<<40});
	while(Y>1 && X<=R) {
		
		ll t=0;
		for(v=1LL<<40;v>0;v>>=1) if(t+v<Y && Experiment(X,t+v)=='T') t+=v;
		if(t==0) break;
		Y=t;
		V.push_back({X,Y});
		for(v=1LL<<40;v>0;v>>=1) if(X+v<=R) {
			if(Experiment(X+v,Y)=='T') X+=v;
		}
		V.push_back({X,Y});
		X++;
	}
	
	ll ret=0;
	FOR(i,V.size()-1) {
		(ret += ((V[i+1].first-V[i].first)%mo)*(V[i+1].second%mo))%=mo;
	}
	cout<<ret<<endl;
	
}

void fast() {
	int i,j,k,l,r,x,y; string s;
	
}

void solve(){
	
	N=GetNumNanobots();
	R=GetRange();
	if(N<=100000) slow();
	else fast();
}


int main(int argc,char** argv){
	
	TN=NumberOfNodes();
	MY=MyNodeId();
	solve();
	return 0;
	
}


