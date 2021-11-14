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
    bool checkAlmostEquivalent(string word1, string word2) {
        int i;
        FOR(i,26) {
			int C=0;
			FORR(c,word1) if(c=='a'+i) C++;
			FORR(c,word2) if(c=='a'+i) C--;
			if(abs(C)>3) return 0;
		}
		return 1;
    }
};
