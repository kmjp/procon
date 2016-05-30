#include <message.h>
#include <stdio.h>
#include <bits/stdc++.h>
#include "oops.h"
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

#define MASTER_NODE 7
#define DONE -1

int main() {
	long long N = GetN();
	long long nodes = NumberOfNodes();
	long long my_id = MyNodeId();
	int i;
	ll mi=1LL<<60;
	ll ma=-1LL<<60;
	for (i=my_id;i<N;i+=nodes) {
		ll v=GetNumber(i);
		mi=min(v,mi);
		ma=max(v,ma);
	}
	PutLL(MASTER_NODE, ma);
	PutLL(MASTER_NODE, mi);
	Send(MASTER_NODE);
	

	if (my_id == MASTER_NODE) {
		FOR(i,nodes) {
			Receive(i);
			ma=max(ma,GetLL(i));
			mi=min(mi,GetLL(i));
		}
		cout<<ma-mi<<endl;
	}
	return 0;
}

