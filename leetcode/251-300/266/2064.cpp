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
    int minimizedMaximum(int n, vector<int>& quantities) {
		ll ret=1<<30;
		int i;
		for(i=29;i>=0;i--) {
			ll tmp=ret-(1<<i);
			ll num=0;
			FORR(q,quantities) num+=(q+tmp-1)/tmp;
			if(num<=n) ret=tmp;
		}
        return ret;
    }
};
