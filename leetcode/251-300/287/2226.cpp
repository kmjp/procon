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
    int maximumCandies(vector<int>& candies, long long k) {
		ll ret=0;
		int i;
		for(i=39;i>=0;i--) {
			ll tmp=ret+(1LL<<i);
			ll num=0;
			FORR(c,candies) num+=c/tmp;
			if(num>=k) ret=tmp;
		}
        return ret;
    }
};
