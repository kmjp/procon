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
    int canBeTypedWords(string text, string brokenLetters) {
		int C[256]={};
		FORR(c,brokenLetters) C[c]=1;
		text+=" ";
		int ret=0;
		int cur=1;
		FORR(c,text) {
			if(c==' ') {
				ret+=cur;
				cur=1;
			}
			else {
				if(C[c]==1) cur=0;
			}
		}
        return ret;
    }
};
