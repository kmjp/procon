#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))

class Solution {
public:
    int minAddToMakeValid(string S) {
		int cur=0;
		int ret=0;
		FORR(c,S) {
			if(c=='(') cur++;
			else cur--;
			if(cur<0) {
				ret++;
				cur++;
			}
		}
		return ret+cur;
    }
};
