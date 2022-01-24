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
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
		ll ma=0,mi=0,cur=0;
		FORR(d,differences) {
			cur+=d;
			ma=max(ma,cur);
			mi=min(mi,cur);
		}
		if(ma-mi>upper-lower) return 0;
		return (upper-lower)-(ma-mi)+1;
        
    }
};