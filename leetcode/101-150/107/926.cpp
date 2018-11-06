#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))

int N;
int L[202020];
int R[202020];

class Solution {
public:
	int minFlipsMonoIncr(string S) {
		N=S.size();
		int i;
		FOR(i,N) L[i+1]=L[i]+(S[i]=='1');
		FOR(i,N) R[i+1]=R[i]+(S[N-1-i]=='0');
		int mi=202020;
		FOR(i,N+1) mi=min(mi,L[i]+R[N-i]);
		return mi;
	}
};
