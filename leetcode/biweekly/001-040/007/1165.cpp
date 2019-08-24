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

    int calculateTime(string keyboard, string word) {
		int i,j;
		int cur=0,ret=0;
		FOR(i,word.size()) {
			FOR(j,26) if(word[i]==keyboard[j]) break;
			ret+=abs(j-cur);
			cur=j;
		}
		return ret;
        
    }


};

