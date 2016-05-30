#include <message.h>
#include <bits/stdc++.h>
#include "crates.h"
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
ll H[1010100];
ll A[1010100];
ll mo=1000000007;
ll TS[101];
ll TA[101];

void solve(){
	int i,j,k,l,r,x,y; string s;
	
	N=GetNumStacks();
	if(N<=3*TN) {
		if(MY!=0) return;
		ll sum=0;
		FOR(i,N) H[i]=GetStackHeight(i+1), sum+=H[i];
		FOR(i,N) A[i]=sum/N + (i<(sum%N));
		
		ll tot=0;
		FOR(i,N-1) {
			tot += abs(A[i]-H[i]);
			H[i+1] += H[i]-A[i];
			tot %= mo;
		}
		cout<<tot<<endl;
	}
	else {
		int step=(N+TN-1)/TN;
		int st=step*MY;
		int ed=min(step*(MY+1),(int)N);
		
		ll mysum=0;
		for(i=st;i<ed;i++) mysum += GetStackHeight(i+1);
		PutLL(0,mysum);
		Send(0);
		
		ll sum=0;
		ll ret=0;
		if(MY==0) {
			FOR(i,TN) {
				Receive(i);
				TS[i] = GetLL(i);
				sum += TS[i];
			}
			FOR(i,TN) {
				int st1=step*i;
				int ed1=min(step*(i+1),(int)N);
				TA[i] = sum/N*(ed1-st1);
				if(st1<sum%N) TA[i] += min(sum%N,(ll)ed1)-st1;
			}
			FOR(i,TN-1) {
				ret += abs(TS[i]-TA[i]);
				TS[i+1] += TS[i]-TA[i];
				PutLL(i+1,sum);
				PutLL(i+1,TS[i]-TA[i]);
				Send(i+1);
			}
		}
		
		ll delta = 0;
		if(MY!=0) {
			Receive(0);
			sum = GetLL(0);
			delta = GetLL(0);
		}
		for(i=st;i<ed-1;i++) {
			ll cur = GetStackHeight(i+1) + delta;
			ll tar = sum/N + (i<(sum%N));
			ret += abs(tar-cur);
			delta = cur-tar;
			ret %= mo;
		}
		if(MY!=0) {
			PutLL(0,ret);
			Send(0);
		}
		else {
			for(i=1;i<TN;i++) {
				Receive(i);
				ret += GetLL(i);
			}
			cout<<ret%mo<<endl;
		}
		
		
		
	}
	
}


int main(int argc,char** argv){
	
	TN=NumberOfNodes();
	MY=MyNodeId();
	solve();
	return 0;
	
}


