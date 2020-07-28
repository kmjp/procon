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
    int numSplits(string s) {
        int A[26]={};
        int B[26]={};
        int N=s.size();
        FORR(c,s) A[c-'a']++;
        int ret=0;
        int i,j;
        FOR(i,N-1) {
			char c=s[i]-'a';
			A[c]--;
			B[c]++;
			int D=0;
			FOR(j,26) {
				if(A[j]) D++;
				if(B[j]) D--;
			}
			if(D==0) ret++;
		}
		return ret;
    }
};


