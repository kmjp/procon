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
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
		int ret=0;
		int i;
		FOR(i,30) {
			int X=0,Y=0;
			FORR(a,arr1) if(a&(1<<i)) X++;
			FORR(a,arr2) if(a&(1<<i)) Y++;
			if(1LL*X*Y%2) ret|=1<<i;
		}
		return ret;
        
    }
};
