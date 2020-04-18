#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))


int replace(int N, char S[]) {
	int D[5]={0,1<<30,1<<30,1<<30,1<<30};
	
	int i;
	int mi=4;
	FOR(i,N) {
		char c=S[i];
		D[4]=min(D[4],D[3]+(c!='C'));
		D[3]=min(D[3],D[2]+(c!='P'));
		D[2]=min(D[2],D[1]+(c!='J'));
		D[1]=min(D[1],D[0]+(c!='I'));
	}
	
	
	return D[4];
}
