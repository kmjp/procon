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
    int minimumCost(vector<int>& cost) {
		sort(ALL(cost));
		reverse(ALL(cost));
		int ret=0,i;
		FOR(i,cost.size()) {
			if(i%3!=2) ret+=cost[i];
		}
		return ret;
        
    }
};
