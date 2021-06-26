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
    long long maxAlternatingSum(vector<int>& nums) {
        ll from[2]={0,-1LL<<60};
        FORR(n,nums) {
			ll to[2]={from[0],from[1]};
			to[0]=max(to[0],from[1]-n);
			to[1]=max(to[1],from[0]+n);
			swap(from,to);
		}
		return max(from[0],from[1]);
    }
};
