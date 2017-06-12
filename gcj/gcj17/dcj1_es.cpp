#include <message.h>
#include <cassert>
#include <cstdio>
#include "query_of_death.h"
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
ll N;

void slow() {
	int i,j,k,l,r,x,y; string s;
	if(MY>1) return;
	
	if(MY==0) {
		int ret=0;
		FOR(i,N) {
			x=0;
			int first=GetValue(i);
			FOR(y,99) x+=GetValue(i);
			ret+=first;
			if(first+x!=0 && first+x!=100) break;
		}
		Receive(1);
		ret+=GetInt(1);
		cout<<ret<<endl;
		
	}
	else {
		int ret=0;
		for(i=N-1;i>=0;i--) {
			x=0;
			FOR(y,100) x+=GetValue(i);
			if(x!=0 && x!=100) break;
			ret += x/100;
		}
		PutInt(0,ret);
		Send(0);
	}
}
void fast() {
	int i,j,k,l,r,x,y; string s;
	ll L=N*(MY/2)/(TN/2);
	ll R=N*((MY/2)+1)/(TN/2);
	
	ll ret=0;
	if(MY%2==0) {
		for(int i=L;i<R;i++) {
			x=0;
			int first=GetValue(i);
			FOR(y,6) x+=GetValue(i);
			ret+=first;
			if(first+x!=0 && first+x!=7) break;
		}
	}
	else {
		for(i=R-1;i>=L;i--) {
			x=0;
			FOR(y,7) x+=GetValue(i);
			if(x!=0 && x!=7) break;
			ret += x/7;
		}
		if(i==L-1) ret=0;
	}
	PutInt(0,ret);
	Send(0);
	
	if(MY!=0) return;
	ret=0;
	FOR(i,TN) {
		Receive(i);
		ret+=GetInt(i);
	}
	cout<<ret<<endl;
	
}

void solve(){
	N=GetLength();
	
	if(N<=1000) slow();
	else fast();
}


int main(int argc,char** argv){
	
	TN=NumberOfNodes();
	MY=MyNodeId();
	solve();
	return 0;
	
}


