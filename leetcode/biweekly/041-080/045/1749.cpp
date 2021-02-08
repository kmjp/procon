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
    int maxAbsoluteSum(vector<int>& nums) {
        ll mi=0,ma=0;
        ll cur=0;
        ll ret=0;
        FORR(n,nums) {
			cur+=n;
			ret=max(ret,abs(cur-mi));
			ret=max(ret,abs(cur-ma));
			mi=min(mi,cur);
			ma=max(ma,cur);
		}
		return ret;
    }
};
