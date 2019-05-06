typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------


class Solution {
public:
	int N;
	vector<int> S;
	
	int hogemin() {
		int ret=N+1;
		int L,R=0;
		FOR(L,N) {
			R=max(R,L+1);
			while(R<N&&S[R]-S[L]<N) R++;
			if((R<N&&L)||R<N-1||S[R-1]==S[L]+N-1) ret=min(ret,N-(R-L));
		}
		reverse(ALL(S));
		FORR(v,S) v=-v;
		R=0;
		FOR(L,N) {
			R=max(R,L+1);
			while(R<N&&S[R]-S[L]<N) R++;
			if((R<N&&L)||R<N-1||S[R-1]==S[L]+N-1) ret=min(ret,N-(R-L));
		}
		reverse(ALL(S));
		FORR(v,S) v=-v;
		
		return ret;
	}
	int hogemax() {
		// left
		return max(S[N-2]-S[0]-1,S[N-1]-S[1]-1)-(N-3);
	}
	
    vector<int> numMovesStonesII(vector<int>& S_) {
		S=S_;
		N=S.size();
		sort(ALL(S));
		
		return {hogemin(),hogemax()};
		
        
    }
};
