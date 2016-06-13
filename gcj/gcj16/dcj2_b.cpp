#include <message.h>
#include <bits/stdc++.h>
#include "again.h"
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
ll mo=1000000007;
ll tota[20];
ll totb[20];

void solve(){
	int i,j,k,l,r,x,y; string s;
	N=GetN();
	
	if(MY>=20) return;
	for(i=MY;i<N;i+=20) {
		tota[MY] += GetA(i);
		totb[MY] += GetB(i);
	}
	
	PutLL(0, tota[MY]%mo);
	PutLL(0, totb[MY]%mo);
	Send(0);
	
	if(MY==0) {
		
		FOR(i,20) {
			Receive(i);
			tota[i]=GetLL(i);
			totb[i]=GetLL(i);
		}
		
		ll ret=0;
		FOR(x,20) FOR(y,20) if((x+y)%20!=0) ret += (tota[x]%mo)*(totb[y]%mo)%mo;
		cout<<ret%mo<<endl;
	}
	
}


int main(int argc,char** argv){
	
	TN=NumberOfNodes();
	MY=MyNodeId();
	solve();
	return 0;
	
}


