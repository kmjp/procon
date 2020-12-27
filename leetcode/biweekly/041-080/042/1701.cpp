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
    double averageWaitingTime(vector<vector<int>>& customers) {
		ll sum=0;
		int pre=0;
		FORR(c,customers) {
			ll end=max(c[0],pre)+c[1];
			sum+=end-c[0];
			pre=end;
		}
        return sum*1.0/customers.size();
    }
};
