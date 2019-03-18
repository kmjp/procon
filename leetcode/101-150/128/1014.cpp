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
	int ok(ll v,vector<int>& weights, int D) {
		int day=1;
		ll lef=v;
		FORR(w,weights) {
			if(w>v) return 0;
			if(lef>=w) {
				lef-=w;
			}
			else {
				day++;
				lef=v-w;
			}
		}
		return day<=D;
	}
    int shipWithinDays(vector<int>& weights, int D) {
        ll ret=1<<30;
        for(int i=29;i>=0;i--) if(ok(ret-(1<<i),weights,D)) ret-=1<<i;
        return ret;
        
    }
};
