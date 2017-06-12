#include <message.h>
#include <cassert>
#include <cstdio>
#include "flagpoles.h"
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
ll H[10101000];

void slow() {
	int i,j,k,l,r,x,y; string s;
	if(MY!=0) return;
	
	FOR(i,N) H[i]=GetHeight(i);
	
	int ma=1;
	x=0;
	while(x<N-1) {
		ll D=H[x+1]-H[x];
		y=x+2;
		while(y<N && H[y]-H[y-1]==D) y++;
		ma=max(ma,y-x);
		x=y-1;
	}
	cout<<ma<<endl;
	
	
}

void fast() {
	int i,j,k,l,r,x,y; string s;
	
	ll L=N*MY/TN;
	ll R=N*(MY+1)/TN;
	ll W=R-L;
	FOR(i,W) H[i]=GetHeight(L+i);
	
	int ma=1;
	x=0;
	while(x<W-1) {
		ll D=H[x+1]-H[x];
		y=x+2;
		while(y<N && H[y]-H[y-1]==D) y++;
		ma=max(ma,y-x);
		x=y-1;
	}
	
	ll LD=H[1]-H[0];
	ll RD=H[W-1]-H[W-2];
	int LS,RS;
	for(LS=1;LS<W;LS++) {
		if(H[LS]-H[LS-1]!=LD) break;
	}
	for(RS=1;RS<W;RS++) {
		if(H[W-RS]-H[W-RS-1]!=RD) break;
	}
	
	PutInt(0,ma);
	PutLL(0,W);
	PutLL(0,H[0]);
	PutLL(0,LD);
	PutLL(0,LS);
	PutLL(0,H[W-1]);
	PutLL(0,RD);
	PutLL(0,RS);
	Send(0);
	
	if(MY!=0) return;
	
	ll LDS[101],RDS[101],LH[101],RH[101],LSS[101],RSS[101],WS[101];
	ma=0;
	FOR(i,TN) {
		Receive(i);
		ma=max(ma,GetInt(i));
		WS[i]=GetLL(i);
		LH[i]=GetLL(i);
		LDS[i]=GetLL(i);
		LSS[i]=GetLL(i);
		RH[i]=GetLL(i);
		RDS[i]=GetLL(i);
		RSS[i]=GetLL(i);
	}
	
	FOR(i,TN) {
		if(i==0) {
			x=RSS[0];
		}
		else {
			if(RDS[i-1]==LDS[i] && RH[i-1]+RDS[i-1]==LH[i]) {
				x+=LSS[i];
				ma=max(ma,x);
				if(LSS[i]==WS[i]) continue;
			}
			x=RSS[i];
		}
	}
	
	
	cout<<ma<<endl;
	
}

void solve(){
	
	N=GetNumFlagpoles();
	if(N<=10100) slow();
	else fast();
}


int main(int argc,char** argv){
	
	TN=NumberOfNodes();
	MY=MyNodeId();
	solve();
	return 0;
	
}


