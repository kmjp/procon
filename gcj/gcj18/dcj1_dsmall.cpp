#include <message.h>
#include <cassert>
#include <cstdio>
#include "kenneth.h"
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
int L[101],S[101];
int TS;
char H[10100000];

void slow() {
	int i,j,k,l,r,x,y; string s;
	
	vector<int> cand;
	for(i=1;i*i<=TS;i++) {
		if(TS%i==0) {
			cand.push_back(i);
			if(i*i!=TS) cand.push_back(TS/i);
		}
	}
	sort(ALL(cand));
	FOR(i,L[MY]) H[i]=GetSignalCharacter(S[MY]+i);
	
	set<int> ret;
	FORR(c,cand) {
		if(c>L[0]/2) break;
		FOR(i,L[MY]-c) if(H[i]!=H[i+c]) break;
		if(i==L[MY]-c) ret.insert(c);
	}
	
	if(MY!=0) {
		PutInt(0,ret.size());
		FORR(c,ret) PutInt(0,c);
		Send(0);
		return;
	}
	
	for(int node=1;node<TN;node++) {
		set<int> ok;
		Receive(node);
		x=GetInt(node);
		while(x--) {
			y=GetInt(node);
			if(ret.count(y)) ok.insert(y);
		}
		swap(ok,ret);
	}
	cout<<*ret.begin()<<endl;
	
}

/*
void fast() {
	int i,j,k,l,r,x,y; string s;
	
	int L=S*MY/TN;
	int R=S*(MY+1)/TN;
	
	int pre=1<<30;
	int cnt=0;
	if(L>0) pre=GetStackItem(L-1);
	
	for(i=L;i<R;i++) {
		x=GetStackItem(i);
		if(x<pre) cnt++;
		pre=x;
	}
	
	PutInt(0,cnt);
	Send(0);
	
	if(MY==0) {
		int ret=0;
		FOR(i,TN) {
			Receive(i);
			ret+=GetInt(i);
		}
		cout<<ret<<endl;
	}
}
*/

void solve(){
	
	int i;
	FOR(i,TN) {
		L[i]=GetPieceLength(i);
		S[i+1]=S[i]+L[i];
		TS+=L[i];
	}
	
	slow();
	/*
	if(S<=1000) slow();
	else fast();
	*/
}


int main(int argc,char** argv){
	
	TN=NumberOfNodes();
	MY=MyNodeId();
	solve();
	return 0;
	
}


