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
    vector<int> memLeak(int memory1, int memory2) {
		int i;
        for(i=1;i<=1000000;i++) {
			if(memory1>=memory2) {
				if(i>memory1) break;
				memory1-=i;
			}
			else {
				if(i>memory2) break;
				memory2-=i;
			}
		}
		return {i,memory1,memory2};
    }
};
 