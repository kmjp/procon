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
	int valid(vector<int>& A) {
		if(A[2]>=6) return 0;
		if(A[0]>=3) return 0;
		if(A[0]==2 && A[1]>=4) return 0;
		return 1;
	}
    string largestTimeFromDigits(vector<int>& A) {
		string S;
		sort(ALL(A));
		do {
			if(valid(A)) {
				char buf[10];
				sprintf(buf,"%d%d:%d%d",A[0],A[1],A[2],A[3]);
				S=buf;
			}
		} while(next_permutation(ALL(A)));
		return S;
    }
};
