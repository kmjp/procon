#include <message.h>
#include <cassert>
#include <cstdio>
#include "number_bases.h"
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
ll X[1010101],Y[1010101],Z[1010101];

void slow() {
	int i,j,k,l,r,x,y; string s;
	if(MY!=0) return;
	
	ll ma=0;
	ll cand=0;
	FOR(i,N) {
		X[i]=GetDigitX(i);
		Y[i]=GetDigitY(i);
		Z[i]=GetDigitZ(i);
		ma=max({ma,X[i]+1,Y[i]+1,Z[i]+1});
		X[i]+=Y[i];
		if(cand==0 && X[i]!=Z[i]) cand=abs(X[i]-Z[i]);
	}
	if(cand==0) {
		cout<<"NON-UNIQUE"<<endl;
		return;
	}
	
	vector<int> V;
	for(x=ma;x<=cand;x++) if(cand%x==0) {
		ll carry=0;
		FOR(i,N) {
			ll dif=X[i]-Z[i]+carry;
			if(dif%x) break;
			carry = dif/x;
		}
		if(i==N && carry==0) V.push_back(x);
		
	}
	if(V.size()==0) {
		cout<<"IMPOSSIBLE"<<endl;
	}
	else if(V.size()>=2) {
		cout<<"NON-UNIQUE"<<endl;
	}
	else {
		cout<<V[0]<<endl;
	}
	
}

void fast() {
	int i,j,k,l,r,x,y; string s;
	
	int L=1LL*N*MY/TN;
	int R=1LL*N*(MY+1)/TN;
	int W=R-L;
	
	ll cand=0,ma=0;
	FOR(i,W) {
		X[i]=GetDigitX(i+L);
		Y[i]=GetDigitY(i+L);
		Z[i]=GetDigitZ(i+L);
		ma=max({ma,X[i]+1,Y[i]+1,Z[i]+1});
		X[i]+=Y[i];
		if(cand==0 && X[i]!=Z[i]) cand=abs(X[i]-Z[i]);
	}
	PutInt(0,cand);
	PutInt(0,ma);
	Send(0);
	
	if(MY==0) {
		cand=ma=0;
		FOR(i,TN) {
			Receive(i);
			x=GetInt(i);
			y=GetInt(i);
			if(cand==0) cand=x;
			ma=max(ma,(ll)y);
		}
		
		FOR(i,TN) {
			PutInt(i,cand);
			PutInt(i,ma);
			Send(i);
		}
	}
	
	Receive(0);
	cand = GetInt(0);
	ma = GetInt(0);
	
	if(cand==0) {
		if(MY==0) {
			cout<<"NON-UNIQUE"<<endl;
		}
		return;
	}
	
	vector<pair<int,int>> V[5];
	for(x=ma;x<=cand;x++) if(cand%x==0) {
		FOR(y,5) {
			ll carry=y-2;
			FOR(i,W) {
				ll dif=X[i]-Z[i]+carry;
				if(dif%x) break;
				carry = dif/x;
			}
			if(i==W) V[y].push_back({x,carry});
		}
	}
	
	FOR(y,5) {
		PutInt(0,V[y].size());
		FORR(v,V[y]) {
			PutInt(0,(int)v.first);
			PutInt(0,(int)v.second);
		}
	}
	Send(0);
	
	if(MY!=0) return;
	map<int,int> carrys[101][5];
	FOR(i,TN) {
		Receive(i);
		FOR(y,5) {
			x=GetInt(i);
			while(x--) {
				j=GetInt(i);
				k=GetInt(i);
				carrys[i][y][j]=k;
			}
		}
	}
	
	vector<int> ret;
	FORR(r,carrys[0][2]) {
		x=r.first;
		int c=r.second;
		for(i=1;i<TN;i++) {
			if(carrys[i][c+2].count(x)==0) break;
			c=carrys[i][c+2][x];
		}
		if(i==TN && c==0) ret.push_back(x);
	}
	
	if(ret.size()==0) {
		cout<<"IMPOSSIBLE"<<endl;
	}
	else if(ret.size()>=2) {
		cout<<"NON-UNIQUE"<<endl;
	}
	else {
		cout<<ret[0]<<endl;
	}
	
	
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


