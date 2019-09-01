
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
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
		ll S=0;
		int point=0;
		int i;
		FOR(i,calories.size()) {
			S+=calories[i];
			if(i>=k) S-=calories[i-k];
			if(i>=k-1) {
				if(S<lower) point--;
				if(S>upper) point++;
			}
		}
		return point;
        
    }
};
