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
    string smallestNumber(string pattern) {
        string S;
        int N=pattern.size();
        int i;
        FOR(i,N+1) S+='1'+i;
        do {
			FOR(i,N) {
				if(pattern[i]=='D'&&S[i]<S[i+1]) break;
				if(pattern[i]=='I'&&S[i]>S[i+1]) break;
			}
			if(i==N) return S;
			
		} while(next_permutation(ALL(S)));
		return "";
    }
};
