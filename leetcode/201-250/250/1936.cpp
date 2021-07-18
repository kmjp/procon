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
    int addRungs(vector<int>& rungs, int dist) {
		int ret=0;
		int i;
		int x=rungs[0];
		ret+=(x+dist-1)/dist-1;
		FOR(i,rungs.size()-1) {
			int x=rungs[i+1]-rungs[i];
			ret+=(x+dist-1)/dist-1;
		}
		return ret;
        
    }
};
