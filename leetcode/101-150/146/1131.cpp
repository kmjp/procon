
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
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
		ll pp=-(1LL<<40);
		ll pm=-(1LL<<40);
		ll mp=-(1LL<<40);
		ll mm=-(1LL<<40);
		
		int i;
		ll ret=0;
		FOR(i,arr1.size()) {
			ret=max(ret,arr1[i]+arr2[i]+mm+i);
			ret=max(ret,arr1[i]-arr2[i]+mp+i);
			ret=max(ret,-arr1[i]+arr2[i]+pm+i);
			ret=max(ret,-arr1[i]-arr2[i]+pp+i);
			pp=max(pp,(ll)arr1[i]+arr2[i]-i);
			pm=max(pm,(ll)arr1[i]-arr2[i]-i);
			mp=max(mp,(ll)-arr1[i]+arr2[i]-i);
			mm=max(mm,(ll)-arr1[i]-arr2[i]-i);
			
		}
		
		return ret;
        
    }
};

