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
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
		int C[1010]={};
		FORR(a,boxTypes) C[a[1]]+=a[0];
		int ret=0;
		int i;
		for(i=1000;i>=1;i--) {
			int x=min(truckSize,C[i]);
			ret+=x*i;
			truckSize-=x;
		}
		return ret;
        
    }
};

