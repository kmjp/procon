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
    long long minimumTime(vector<int>& time, int totalTrips) {
		ll ret=1LL<<60;
		int i,j;
		for(i=59;i>=0;i--) {
			ll tmp=ret-(1LL<<i);
			ll num=0;
			FOR(j,time.size()) {
				num+=tmp/time[j];
				num=min(num,1LL<<60);
			}
			if(num>=totalTrips) ret=tmp;
		}
        return ret;
    }
};
